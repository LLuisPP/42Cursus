/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerParsePrivmsg.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:36:55 by flperez-          #+#    #+#             */
/*   Updated: 2026/02/01 17:50:30 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

e_rpl	Server::parsePrivmsg(std::vector<std::string> args, Client *client, std::string *extra) {

	*extra = "PRIVMSG";
	if (args.size() < 2) 
		return ERR_NORECIPIENT;
	if (args.size() < 3) 
		return ERR_NOTEXTTOSEND;

	std::string target = args[1];
	std::string message = "";

	if (args.size() > 2) {
		message = args[2];
		if (!message.empty() && message[0] == ':')
			message.erase(0, 1);
		for (size_t i = 3; i < args.size(); i++) {
			message += " " + args[i];
		}
	}

	std::string prefix = ":" + client->getNickname() + "!" + client->getUserName() + "@localhost";
	std::string fullMsg = prefix + " PRIVMSG " + target + " :" + message + "\r\n";

	if (target[0] == '#') {
		if (!_channel_list.count(target))
			return ERR_NOSUCHCHANNEL;

		Channel &chan = _channel_list[target];

		// Verify that the user is a member of the channel before allowing to speak
		if (!chan.isInChannelUserList(client->getNickname()))
			 return ERR_CANNOTSENDTOCHAN;

		std::map<std::string, Client*> &users = chan.getUserList();
		for (std::map<std::string, Client*>::iterator it = users.begin(); it != users.end(); ++it) {
			if (it->second != client) {
				it->second->answer(fullMsg);
			}
		}
	}
	else {
			if (!_client_list_name.count(target))
			return ERR_NOSUCHNICK; // 401: No existe ese nick

		Client *destClient = _client_list_name[target];
		destClient->answer(fullMsg);
	}
	return EXIT;
}