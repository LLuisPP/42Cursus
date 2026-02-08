/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChannelExecuters.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:26:21 by lgracia-          #+#    #+#             */
/*   Updated: 2026/02/01 21:19:59 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

/* EXECUTERS */

/* Add a client to the channel's user list */
e_rpl	Channel::addUser(Client* client)
{
	if (_user_list.count(client->getNickname()))
		return (ERR_USERONCHANNEL);

	// Limit verification (+l)
	if (_mode_l && _limit_n_users > 0 && _user_list.size() >= _limit_n_users)
		return (ERR_CHANNELISFULL);

	// invite verification (+i)
	if (_mode_i && !_invite_list.count(client->getNickname()))
		return (ERR_INVITEONLYCHAN);
	
    _user_list[client->getNickname()] = client;

	// We remove the invitation that has been used; the list should only contain invitations pending use.
	if (_invite_list.count(client->getNickname()))
		_invite_list.erase(client->getNickname());

	return (EXIT);
}

/* Delete a client form a channel */
void	Channel::deleteUser(Client* client) {
	
	_user_list.erase(client->getNickname());
}

/* Promote a client to channel operator */
void	Channel::addUserOperator(Client* client) {

    _operator_list[client->getNickname()] = client;
}

/* Remove operator privileges from a client */
void	Channel::deleteUserOperator(Client* client) {
	
	_operator_list.erase(client->getNickname());
}

/* Add the customer to the guest list */
void	Channel::addUserInvite(Client* client) {
	
	_invite_list[client->getNickname()] = client;
}

/* Remove the client from the guest list */
void	Channel::deleteUserInvite(Client* client) {
	
	_invite_list.erase(client->getNickname());
}

/* Sends the same message to all users of the channel */
void	Channel::spreadMsg(std::string msg) {
	
	for (std::map<std::string, Client*>::iterator i = _user_list.begin(); i != _user_list.end(); i++)
		i->second->answer(msg);
}

/* Check if there are any user left */
bool	Channel::usersLeft() {
	
	if (_user_list.size() == 0)
		return 1;
	this->operatorsLeft();
	return 0;
}

/* Check if there are any operators left and add the first user on the list as an operator */
void	Channel::operatorsLeft() {

	if (_operator_list.size() == 0)
	{
		this->addUserOperator(_user_list.begin()->second);
		this->spreadMsg(":localhost MODE " + this->_channel_name + " +o "  + _user_list.begin()->second->getNickname() + "\r\n");
	}
}
