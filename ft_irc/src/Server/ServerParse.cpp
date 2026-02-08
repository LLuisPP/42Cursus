/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerParse.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:03:03 by flperez-          #+#    #+#             */
/*   Updated: 2026/02/02 17:50:12 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

/* PARSE INIT */

void	Server::parseInit(std::string client_line, Client* client) {

	if (client_line.empty())
		return;

	std::stringstream ss(client_line);
	std::string line;
	
	while (std::getline(ss, line))
	{
		if (!line.empty() && line[line.size() - 1] == '\r')
			line.erase(line.size() - 1);
		if (line.empty())
			continue;
		if (get_monitoring(0, 0))
			logInput(client->getFd(), line);

		e_rpl result = EXIT;
		std::string	extra = "";
		std::string channel = "";

		if (client->getState() == AUTHENTICATED) {
			result = parseCommand(line, client, &channel, &extra);
		} else
			result = parseAuthentication(line, client, &extra);
		
		if (result != EXIT && result != 0) {
			replySorting(result, client, channel, extra);
			if (result == ERR_PASSWDMISMATCH) {
				close(client->getFd());
				return; 
			}
		}
	}
}

e_rpl	Server::parseAuthentication(std::string cmd_line, Client *client, std::string *extra) {
	
	std::vector<std::string> args = splitCommand(cmd_line);
	if (args.empty())
		return (EXIT);
		
	std::string cmd = args[0];

	if (cmd == "CAP") {
		if (client->getState() == NOT_AUTHENTICATED)
			client->setState(CAP_NEGOTIATED);
		return (EXIT);
	}

	if (cmd == "PASS") {
		if (client->getState() == PASS_OK || client->getState() >= NICK_OK)
			return (ERR_ALREADYREGISTRED);
		
		e_rpl err = parsePassword(args, client);
		if (err == EXIT) {
			client->setState(PASS_OK);
			std::cout << "Cliente " << client->getFd() << ": Password OK" << std::endl;
		}
		return (err);
	}

	if (cmd == "NICK") {
		if (client->getState() < PASS_OK)
			return ERR_PASSWDMISMATCH;
		return parseNickName(args, client, extra);
	}

	if (cmd == "USER") {
		if (client->getState() < PASS_OK)
			return (ERR_NOTREGISTERED);
		e_rpl err = parseUserName(args, client);
		if (err == RPL_WELCOME)
			client->setState(AUTHENTICATED);
		return (err);
	}
	return (EXIT);
}

/* COMMAND DISPATCHER (Chat) */

e_rpl Server::parseCommand(std::string cmd_line, Client* client, std::string *channel, std::string *extra) {

	std::vector<std::string> args = splitCommand(cmd_line);
	if (args.empty()) return (EXIT);
	std::string cmd = args[0];
	if (cmd == "NICK") return parseNickName(args, client, extra);
	if (cmd == "PRIVMSG") return (parsePrivmsg(args, client, extra));
	if (cmd == "JOIN") return (parseJoin(args, client, channel, extra));
	if (cmd == "INVITE") return (parseInvite(args, client, channel, extra));
	if (cmd == "KICK") return (parseKick(args, client, channel, extra));
	if (cmd == "MODE") return (parseMode(args, client, channel, extra));
	if (cmd == "WHO") return (parseWho(args, client, channel, extra));
	if (cmd == "TOPIC") return (parseTopic(args, client, channel, extra));
	if (cmd == "PART") return (parsePart(args, client, channel, extra));
	if (cmd == "QUIT") return (parseQuit(args, client));

	if (cmd == "PING") {
		std::string token = (args.size() > 1) ? args[1] : "";
		std::string pong = "PONG " + token + "\r\n";
		client->answer(pong);
		return (EXIT);
	}
	return (ERR_UNKNOWNCOMMAND);
}

/* ************************************************************************** */
/* IMPLEMENTATIONS                                                            */
/* ************************************************************************** */

e_rpl Server::parsePassword(std::vector<std::string> args, Client *client) {

	if (args.size() < 2) return (ERR_NEEDMOREPARAMS);
	
	// We add cleanup of ":" in case HexChat sends them; this is the other error we were getting.
	// Sometimes HexChat sends the password prefixed with ":", especially when it reconnects automatically.
	// Our code is currently comparing ":1234" == "1234", so we must ensure the colon is removed.

	std::string pass = args[1];
	if (pass.length() > 0 && pass[0] == ':') {
		pass.erase(0, 1);
	} 	

	if (pass != this->_password) return (ERR_PASSWDMISMATCH);
	
	client->setState(PASS_OK);
	return (EXIT);
}

/* NICK: Handles nickname changes and updates channels/operators.
   Fixed version that synchronizes with channels.*/

e_rpl Server::parseNickName(std::vector<std::string> args, Client *client, std::string *extra) {

	if (args.size() < 2) return (ERR_NONICKNAMEGIVEN);
	std::string newNick = args[1];

	/* Validation of nickname already in use */
	Client* collision = getClientNick(newNick);
	if (collision != NULL && collision != client)
		return (ERR_NICKNAMEINUSE);

	if (newNick.at(0) == '#')
	{
		*extra = newNick;
		return (ERR_ERRONEUSNICKNAME);
	}
	/* CASE 1: Client already authenticated — notify change and update channels */
	if (client->getState() == AUTHENTICATED) {
		std::string oldNick = client->getNickname();

		if (_client_list_name.find(oldNick) != _client_list_name.end())
			_client_list_name.erase(oldNick);

		std::vector<std::string> opChannels;

		for (std::map<std::string, Channel>::iterator it = _channel_list.begin(); it != _channel_list.end(); ++it) {
			Channel &chan = it->second;
			if (chan.getUserList().count(oldNick)) {
				
				if (chan.isInChannelOperatorList(oldNick)) {
					opChannels.push_back(it->first);
					chan.deleteUserOperator(client); 
				}
				chan.getUserList().erase(oldNick);
				chan.getUserList()[newNick] = client;
			}
		}

		client->answer(":" + oldNick + " NICK " + newNick + "\r\n");
		client->setNickname(newNick);
		for(size_t i = 0; i < opChannels.size(); i++) {
			_channel_list[opChannels[i]].addUserOperator(client);
		}
	}
	else
		client->setNickname(newNick);

	_client_list_name[newNick] = client;

	if (client->getState() < NICK_OK)
		client->setState(NICK_OK);
	
	/* CASE 2: Complete registration (nickname was missing to connect) */
	if (client->getUserName() != "*" && client->getState() != AUTHENTICATED) {
		client->setState(AUTHENTICATED);
		return (RPL_WELCOME);
	}

	return (EXIT);
}

e_rpl	Server::parseUserName(std::vector<std::string> args, Client *client) {
	
	if (client->getState() < PASS_OK)
		return (ERR_NOTREGISTERED);

	if (args.size() < 5) return (ERR_NEEDMOREPARAMS);
	
	client->setUserName(args[1]);
	
	std::string realname = args[4];
	if (!realname.empty() &&realname[0] == ':')
		realname.erase(0, 1);
	for (size_t i = 5; i < args.size(); i++) {
		realname += " " + args[i];
	}
	client->setRealName(realname);

	if (client->getState() < USER_OK)
		client->setState(USER_OK);
	if (client->getNickname() != "*" && client->getState() != AUTHENTICATED) {
		client->setState(AUTHENTICATED);
		return (RPL_WELCOME);
	}
	
	return (EXIT);
}

e_rpl Server::parseQuit(std::vector<std::string> args, Client *client)
{
	std::string reason = "Quit: leaving";
	if (args.size() > 1) {
		reason = args[1];
		if (!reason.empty() && reason[0] == ':') reason.erase(0, 1);
		for (size_t k = 2; k < args.size(); k++) reason += " " + args[k];
	}
	
	std::string errorMsg = "ERROR :Closing Link: localhost (" + reason + ")\r\n";
	send(client->getFd(), errorMsg.c_str(), errorMsg.length(), 0);

	int clientFd = client->getFd();
	for (size_t i = 0; i < _pfds.size(); i++) {
		if (_pfds[i].fd == clientFd) {
			disconnectClient(i, reason);
			// terminatorClient(_pfds[i].fd, client);
			break;
		}
	}

	return (EXIT); 
}

/*REPLY SORTING (codes to text) */

void Server::replySorting(e_rpl rpl, Client* client, std::string channel, std::string extra)
{
	std::string msg;
	std::string nick = client->getNickname();
	if (nick.empty()) nick = "*";

	std::string prefix = ":localhost " + itoa(rpl) + " " + nick;

	switch (rpl)
	{
		case EXIT:					return;
		case RPL_WELCOME:			msg = prefix + WELCOME + nick + "\r\n"; break;
		case RPL_TOPIC:				msg = prefix + " " + channel + TOPIC+ extra + "\r\n"; break;
		case RPL_NOTOPIC:			msg = prefix + " " + channel + NOTOPIC + "\r\n"; break;
		case RPL_CHANNELMODEIS:		msg = prefix + " " + channel + " :" + extra + "\r\n"; break;
		case RPL_INVITING:			msg = prefix + " " + extra + " " + channel + "\r\n";
			_client_list_name[extra]->answer(":" + nick + " INVITE " + extra + " " + channel + "\r\n"); break;
		// new JOIN
		case RPL_NAMREPLY:			msg = prefix + NAMREPLY + channel + " :" + extra + "\r\n"; break;
		case RPL_ENDOFNAMES:		msg = prefix + channel + ENDOFNAMES + "\r\n"; break;
		// new WHO
		case RPL_WHOREPLY:			msg = prefix + channel + " " +	 extra + "\r\n"; break;
		case RPL_ENDOFWHO:			msg = prefix + channel + ENDOFWHO + "\r\n"; break;
	
		case ERR_NOSUCHNICK:		msg = prefix + " " + channel + " " + extra + NOSUCHNICK; break;
		case ERR_NOSUCHCHANNEL:		msg = prefix + " " + channel + " " + extra + NOSUCHCHANNEL; break;
		case ERR_CANNOTSENDTOCHAN:	msg = prefix + " " + channel + " " + extra + CANNOTSENDTOCHAN; break;
		case ERR_UNKNOWNCOMMAND:	msg = prefix + " " + channel + " " + extra + UNKNOWNCOMMAND; break;
		case ERR_NONICKNAMEGIVEN:	msg = prefix + " " + channel + " " + extra + NONICKNAMEGIVEN; break;
		case ERR_ERRONEUSNICKNAME:	msg = prefix + " " + channel + " " + extra + ERRONEUSNICKNAME; break;
		case ERR_NICKNAMEINUSE:		msg = prefix + " " + channel + " " + extra + NICKNAMEINUSE; break;
		case ERR_USERNOTINCHANNEL:	msg = prefix + " " + channel + " " + extra + USERNOTINCHANNEL; break;
		case ERR_NOTONCHANNEL:		msg = prefix + " " + channel + " " + extra + NOTONCHANNEL; break;
		case ERR_USERONCHANNEL:		msg = prefix + " " + channel + " " + extra + USERONCHANNEL; break;
		case ERR_NOTREGISTERED:		msg = prefix + " " + channel + " " + extra + NOTREGISTERED; break;
		case ERR_NEEDMOREPARAMS:	msg = prefix + " " + channel + " " + extra + NEEDMOREPARAMS; break;
		case ERR_ALREADYREGISTRED:	msg = prefix + " " + channel + " " + extra + ALREADYREGISTRED; break;
		case ERR_PASSWDMISMATCH:	msg = prefix + " " + channel + " " + extra + PASSWDMISMATCH; break;
		case ERR_CHANNELISFULL:		msg = prefix + " " + channel + " " + extra + CHANNELISFULL; break;
		case ERR_UNKNOWNMODE:		msg = prefix + " " + channel + " " + extra + UNKNOWNMODE; break;
		case ERR_INVITEONLYCHAN:	msg = prefix + " " + channel + " " + extra + INVITEONLYCHAN; break;
		case ERR_BADCHANNELKEY:		msg = prefix + " " + channel + " " + extra + BADCHANNELKEY; break;
		case ERR_CHANOPRIVSNEEDED:	msg = prefix + " " + channel + " " + extra + CHANOPRIVSNEEDED; break;
		case ERR_UMODEUNKNOWNFLAG:	msg = prefix + " " + channel + " " + extra + UMODEUNKNOWNFLAG; break;
		
		case BROADCAST:				msg = ":" + client->getNickname() + "!" + client->getUserName() + "@localhost " + extra;//extra = <COMMAND> <channel name> <other variables>
									_channel_list[channel].spreadMsg(msg);
									return ;
		case ERROR_LASTOPERATOR:	msg = ":Can't delete all operators\r\n"; break;
		default: return;
	}
	
	client->answer(msg);
}
