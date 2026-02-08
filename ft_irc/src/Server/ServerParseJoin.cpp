/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerParseJoin.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:33:53 by lgracia-          #+#    #+#             */
/*   Updated: 2026/02/01 17:36:48 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

e_rpl	Server::parseJoin(std::vector<std::string> args, Client *client, std::string *channel, std::string *extra) {

	(void) channel;
	*extra = "JOIN";

	if (args.size() < 2) return (ERR_NEEDMOREPARAMS);

	std::string chanName = args[1];
	std::string key = (args.size() > 2) ? args[2] : ""; 

	if (chanName.empty() || chanName[0] != '#') 
		return (ERR_NEEDMOREPARAMS);
	if (_channel_list.count(chanName)) {
		Channel& channel = _channel_list[chanName];
		if (channel.getMode('k') && channel.getKey() != key) {
			return (ERR_BADCHANNELKEY);
		}
		e_rpl err = channel.addUser(client);
		if (err != EXIT) 
			return (err);
	}
	else
		addNewChannel(chanName, client);
	
	Channel& chanRef = _channel_list[chanName];

	std::string joinExtra = "JOIN :" + chanName + "\r\n";
	replySorting(BROADCAST, client, chanName, joinExtra);
	
	if (!chanRef.getTopic().empty()) { 
		replySorting(RPL_TOPIC, client, chanName, chanRef.getTopic());
	} else
		replySorting(RPL_NOTOPIC, client, chanName, "");

	std::string chanParam = " " + chanName;
	std::string userListStr = chanRef.getNamesList();
	replySorting(RPL_NAMREPLY, client, chanParam, userListStr);
	replySorting(RPL_ENDOFNAMES, client, chanParam, "");
	return (EXIT);
}

e_rpl	Server::parseKick(std::vector<std::string> args, Client *client, std::string *channel, std::string *extra) {

	*extra = "KICK";
	if (args.size() < 3) 
		return ERR_NEEDMOREPARAMS;

	std::string chanName = args[1];
	std::string targetNick = args[2];
	std::string reason = "Kicked by " + client->getNickname();

	if (args.size() > 3) {
		reason = args[3];
		if (reason.size() > 0 && reason[0] == ':'){
			reason.erase(0,1);
		} args[3].erase(0, 1);
		for (size_t i = 4; i < args.size(); i++) {
			reason += " " +args[i];
		}
	}

	if (!_channel_list.count(chanName))
		return ERR_NOSUCHCHANNEL;

	*channel = " " + chanName;
	Channel& chanRef = _channel_list[chanName];
	
	if (!chanRef.isInChannelUserList(client->getNickname()))
		return ERR_NOTONCHANNEL;
	if (!chanRef.isInChannelOperatorList(client->getNickname()))
		return ERR_CHANOPRIVSNEEDED;
	if (!chanRef.isInChannelUserList(targetNick))
		return ERR_USERNOTINCHANNEL;
	if (!_client_list_name.count(targetNick))
		return ERR_NOSUCHNICK;
	
	Client *targetClient = _client_list_name[targetNick];
	std::string kick_msg = "KICK " + chanName + " " + targetNick + " :" + reason + "\r\n";
	replySorting(BROADCAST, client, chanName, kick_msg);

	if (chanRef.isInChannelOperatorList(targetNick))
		chanRef.deleteUserOperator(targetClient);

	chanRef.deleteUser(targetClient);
	
    if (chanRef.usersLeft()) {
        std::cout << "DEBUG KICK: Borrando canal " << chanName << std::endl;
        _channel_list.erase(chanName);
    }
  
	std::cout << "DEBUG KICK: Usuarios restantes en " << chanName << ": " << chanRef.getUserList().size() << std::endl;
	
	if (!chanRef.getUserList().empty()) {
		std::cout << "DEBUG KICK: Lista de usuarios restantes:" << std::endl;
		std::map<std::string, Client*> list = chanRef.getUserList();
		for (std::map<std::string, Client*>::iterator it = list.begin(); it != list.end(); ++it) {
			std::cout << " - " << it->first << std::endl;
		}
	}
	
	if (chanRef.getUserList().empty()) {
		std::cout << "DEBUG KICK: Borrando canal " << chanName << std::endl;
		 _channel_list.erase(chanName);
	}
	return EXIT;
}

e_rpl	Server::parseWho(std::vector<std::string> args, Client *client, std::string *channel, std::string *extra) {
	
	(void)channel;
	*extra = "WHO";
	if (args.size() < 2) 
		return (ERR_NEEDMOREPARAMS);
	
	std::string target = args[1];

	std::string chanParam = " " + target;

	if (!_channel_list.count(target)){
		replySorting(RPL_ENDOFWHO, client, chanParam, "");
		return (EXIT);
	}

	Channel &chan = _channel_list[target];
	std::map<std::string, Client*> &users = chan.getUserList();

	for (std::map<std::string, Client*>::iterator it = users.begin(); it != users.end(); ++it){
		Client *member = it->second;

		std::string flags = "H";
		if (chan.isInChannelOperatorList(member->getNickname()))
			flags += "@";

		std::string whoExtra = member->getUserName() + " localhost localhost " + member->getNickname() + " " + flags + " :0 " + member->getRealName();

		replySorting(RPL_WHOREPLY, client, chanParam, whoExtra);
	}

	replySorting(RPL_ENDOFWHO, client, chanParam, "");

	return EXIT;
}
