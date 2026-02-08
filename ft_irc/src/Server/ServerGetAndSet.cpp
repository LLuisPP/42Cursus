/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerGetAndSet.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:48:24 by lgracia-          #+#    #+#             */
/*   Updated: 2026/02/01 17:00:25 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

/* *********************** Getters *********************** */

std::string Server::getPassword() {

	return _password;
}

Client	*Server::getClientNick(std::string nick_name) {
	
	if (_client_list_name.count(nick_name)) // map verfification
		return _client_list_name[nick_name]; // returns pointer if exists
	return NULL; // returns NULL if it doesn't exist
}

Channel	&Server::getChannel(std::string channel_name) {
	
	return _channel_list[channel_name];
}

int	Server::getSocketFd() {
	
	return _socket_fd;
}

/* *********************** Setters *********************** */

e_rpl	Server::addNewChannel(std::string name, Client *client) {

	_channel_list[name] = Channel(name, client);
	return RPL_INVITING;
}
/* *********************** addChannel ***********************
 * FUNCTION:
 *    Creates and adds a new channel to the channel list map.
 *
 * INPUT: Attributes for the Channel class constructor:
 *      _channel_name
 *
 * OUTPUT: int
 *      RPL_INVITING : e_rpl for success
 *
 * ************************************************************** */

