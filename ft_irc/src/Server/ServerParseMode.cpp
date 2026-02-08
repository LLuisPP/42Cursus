/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerParseMode.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:22:14 by lgracia-          #+#    #+#             */
/*   Updated: 2026/02/02 16:59:57 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

e_rpl	Server::parseMode(std::vector<std::string> cmd_line, Client *client, std::string *channel, std::string *extra) {

	// parse command
	*extra = "MODE";
	if (cmd_line.size() < 2)
		return ERR_NEEDMOREPARAMS;
	if (cmd_line[1].empty() || !_channel_list.count(cmd_line[1]))
		return ERR_NOSUCHCHANNEL;
	if (!_channel_list[cmd_line[1]].isInChannelUserList(client->getNickname()))
		return ERR_NOTONCHANNEL;
	*channel = cmd_line[1];
	if (cmd_line.size() <= 2) {
		*extra = _channel_list[cmd_line[1]].getModesString();
		return RPL_CHANNELMODEIS;
	}
	if (cmd_line[2].size() > 2)
		return ERR_UMODEUNKNOWNFLAG;
	bool sign = 0;
	bool set;
	
	// flag check and bool change for switch
	if (cmd_line[2].size() == 2) {
		switch (cmd_line[2].at(0)) {
			case '+':
				set = true;
				break;
			case '-':
				set = false;
				break;
			default:
				return ERR_UMODEUNKNOWNFLAG;
		}
		if (!_channel_list[cmd_line[1]].isInChannelOperatorList(client->getNickname()))
			return ERR_CHANOPRIVSNEEDED;
		sign = 1;
	}
	// mode execucion with parse vars
	switch (cmd_line[2].at(sign)) {
		case 'i':
			break;
		case 't':
			break;
		case 'k':
			if (sign) {
				if (set) {
					if (set && (cmd_line.size() < 4 || cmd_line[3].empty())) return ERR_NEEDMOREPARAMS;
					_channel_list[cmd_line[1]].setKey(cmd_line[3]);
				}
				else
					_channel_list[cmd_line[1]].setKey("");
			}
			break;
		case 'o':
			if (sign) {
				if ((cmd_line.size() < 4 || cmd_line[3].empty()))
					return ERR_NEEDMOREPARAMS;
				if (!_client_list_name.count(cmd_line[3]))
					return ERR_NOSUCHNICK;
				if (!_channel_list[cmd_line[1]].isInChannelUserList(cmd_line[3]))
					return ERR_USERNOTINCHANNEL;
				if (set) {
					if (_channel_list[cmd_line[1]].isInChannelOperatorList(cmd_line[3]))
						return EXIT;
					_channel_list[cmd_line[1]].addUserOperator(_client_list_name[cmd_line[3]]);
				}
				else {
					if (!_channel_list[cmd_line[1]].isInChannelOperatorList(cmd_line[3]))
						return EXIT;
					if (_channel_list[cmd_line[1]].getNumOperators() == 1 && client->getNickname() == cmd_line[3])
						return ERROR_LASTOPERATOR;
					else
						_channel_list[cmd_line[1]].deleteUserOperator(_client_list_name[cmd_line[3]]);
				}
				*extra = cmd_line[0] + " " + cmd_line[1] + " " + cmd_line[2] + " " + cmd_line[3];
				_channel_list[cmd_line[1]].spreadMsg(":localhost " + *extra + "\r\n");
				return EXIT;
			}
			break;	
		case 'l':
			if (sign) {
				if (set) {
					if ((cmd_line.size() < 4 || cmd_line[3].empty())) 
						return ERR_NEEDMOREPARAMS;
					_channel_list[cmd_line[1]].setLimitNUsers(atoi(cmd_line[3].c_str()));
				}
				else
					_channel_list[cmd_line[1]].setLimitNUsers(MAX_CHANNEL);
			}
			break;
		default:
			return ERR_UMODEUNKNOWNFLAG;
	}

	if (sign && _channel_list[cmd_line[1]].setMode(cmd_line[2].at(sign), set)) {
		*extra = _channel_list[cmd_line[1]].getModesString();
		_channel_list[*channel].spreadMsg(":localhost " + itoa(RPL_CHANNELMODEIS) + " " + client->getNickname() + " " + *channel + " :" + *extra + "\r\n");
		return EXIT;
	}
	*extra = _channel_list[cmd_line[1]].getModesString();
	return RPL_CHANNELMODEIS;
}

e_rpl	Server::parseInvite(std::vector<std::string> cmd_line, Client *client, std::string *channel, std::string *extra) {

	*extra = "INVITE";
	*channel = cmd_line[2];
	if (cmd_line.size() < 3)
		return ERR_NEEDMOREPARAMS;
	if (!_client_list_name.count(cmd_line[1]))
		return ERR_NOSUCHNICK;
	if (!_channel_list.count(cmd_line[2]))
		return ERR_NOSUCHCHANNEL;
	if (!_channel_list[cmd_line[2]].isInChannelUserList(client->getNickname()))
		return ERR_NOTONCHANNEL;
	if (_channel_list[cmd_line[2]].getMode('i') && !_channel_list[cmd_line[2]].isInChannelOperatorList(client->getNickname()))
		return ERR_CHANOPRIVSNEEDED;
	if (_channel_list[cmd_line[2]].isInChannelUserList(cmd_line[1]))
		return ERR_USERONCHANNEL;
	_channel_list[cmd_line[2]].addUserInvite(getClientNick(cmd_line[1]));
	*extra = cmd_line[1];
	return RPL_INVITING;
}

e_rpl	Server::parseTopic(std::vector<std::string> cmd_line, Client *client, std::string *channel, std::string *extra) {

	*extra = "TOPIC";
	*channel = cmd_line[1];
	if (cmd_line.size() < 2)
		return ERR_NEEDMOREPARAMS;
	if (!_channel_list.count(*channel))
		return ERR_NOSUCHCHANNEL;
	if (!_channel_list[*channel].isInChannelUserList(client->getNickname()))
		return ERR_NOTONCHANNEL;
	if (cmd_line.size() > 2) {
		if (_channel_list[*channel].getMode('t') && !_channel_list[*channel].isInChannelOperatorList(client->getNickname()))
			return ERR_CHANOPRIVSNEEDED;
		if (cmd_line[2].size() == 1 && cmd_line[2].at(0) == ':') {
			_channel_list[*channel].setTopic("");
			_channel_list[*channel].spreadMsg(":localhost " + itoa(RPL_NOTOPIC) + " " + client->getNickname() + " " + *channel + " "  + NOTOPIC + "\r\n");
			return EXIT;
		}
		else {
			if (cmd_line[2].size() > 1 && cmd_line[2].at(0) == ':')
				cmd_line[2].erase(0, 1);
			std::string new_topic = "";
			for (size_t i = 2; i < cmd_line.size(); i++)
				new_topic += cmd_line[i] + ' ';
			_channel_list[*channel].setTopic(&new_topic[0]);
			_channel_list[*channel].spreadMsg(":localhost " + itoa(RPL_TOPIC) + " " + client->getNickname() + " " + *channel + TOPIC + _channel_list[*channel].getTopic() + "\r\n");
			return EXIT;
		}
	}
	if (_channel_list[cmd_line[1]].getTopic().empty()) {
		return RPL_NOTOPIC;
	}
	else {
		*extra = _channel_list[*channel].getTopic();
		return RPL_TOPIC;
	}
}

e_rpl Server::parsePart(std::vector<std::string> cmd_line, Client *client, std::string *channel, std::string *extra) {

	*extra = "PART";
	*channel = cmd_line[1];
	if (cmd_line.size() < 2)
		return ERR_NEEDMOREPARAMS;
	if (!_channel_list.count(*channel))
		return ERR_NOSUCHCHANNEL;
	if (!_channel_list[*channel].isInChannelUserList(client->getNickname()))
		return ERR_NOTONCHANNEL;
	if (!cmd_line[2].empty()) {
		if (cmd_line[2].size() > 1 && cmd_line[2].at(0) == ':')
				cmd_line[2].erase(0, 1);
		*extra = "";
		for (size_t i = 2; i < cmd_line.size(); i++)
			*extra += cmd_line[i] + ' ';
	}
	_channel_list[*channel].spreadMsg(":" + client->getNickname() + " "  + cmd_line[0] + " " + *channel + " :" + *extra + "\r\n");
	_channel_list[*channel].deleteUser(client);
	_channel_list[*channel].deleteUserOperator(client);
	if (_channel_list[*channel].usersLeft())
		_channel_list.erase(*channel);
	return EXIT;
}
