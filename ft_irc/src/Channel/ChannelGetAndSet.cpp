/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChannelGetAndSet.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 09:14:41 by lprieto-          #+#    #+#             */
/*   Updated: 2026/02/01 14:53:38 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

std::string	Channel::getName() {
	
	return (_channel_name);
}

/* We convert the internal map of users and operators into the text format specified by the IRC protocol for the participant list:
We check if any user is an operator and identify them by adding "@" in front.
We return the user list formatted for RPL_NAMREPLY:
e.g., "@lorena luis florinda @joan"
> When HexChat reads the string, it will be able to identify who is an administrator and will identify them. */

std::string	Channel::getNamesList() {

    std::string usersStr = "";
    std::map<std::string, Client*>::iterator it;
    
    for (it = _user_list.begin(); it != _user_list.end(); ++it) {
        if (_operator_list.count(it->first))
            usersStr += "@" + it->first + " ";
        else
            usersStr += it->first + " ";
    }
    return usersStr;
}

/* Returns the list of users (Client**) */
std::map<std::string, Client*>	&Channel::getUserList() {
	
	return (_user_list);
}

/* Returns the user limit (0 if there is no limit) */
size_t	Channel::getLimitNUsers() {
	
	return (_limit_n_users);
}

/* Returns the channel key */
std::string	Channel::getKey() {
	
	return (_key);
}

/* Returns the state in a specific way (i, t, k, o, l) */
bool	Channel::getMode(char mode_flag) {

	switch (mode_flag)
	{
		case 'i': return (_mode_i);
		case 't': return (_mode_t);
		case 'k': return (_mode_k);
		case 'l': return (_mode_l);
		default: return (0);
	}
}

std::string	Channel::getModesString() {
	
	std::string modes = "+";
	if (_mode_i) modes += "i";
	if (_mode_t) modes += "t";
	if (_mode_k) modes += "k";
	if (_mode_l) modes += "l";
	if (modes == "+") modes = "";
	return modes;
}

std::string	Channel::getTopic() {
	
	return _topic;
}

size_t	Channel::getNumOperators() {
	
	return _operator_list.size();
}

/* Setters */

/* It sets a channel mode (true/false) */
short	Channel::setMode(char mode_flag, bool set) {
	
	switch (mode_flag)
	{
	case 'i':
		if (_mode_i != set)
		{
			_mode_i = set;
			return 1;
		}
		return 0;
	
	case 't':
		if (_mode_t != set)
		{
			_mode_t = set;
			return 1;
		}
		return 0;

	case 'k':
		if (_mode_k != set)
		{
			_mode_k = set;
			return 1;
		}
		return 0;

	case 'l':
		if (_mode_l != set)
		{
			_mode_l = set;
			return 1;
		}
		return 0;

	default:
		return ERR_UNKNOWNMODE;
	}
}

/* Set the channel key */
std::string	Channel::setKey(std::string new_key) {
	
	_key = new_key;
	return (_key);
}

/* Set the users limit */
size_t	Channel::setLimitNUsers(size_t n) {
	
	_limit_n_users = n;
	return (_limit_n_users);
}

/* Set the channel topic message */
void	Channel::setTopic(std::string new_topic) {
	
	_topic = new_topic;
}

/* returns the channel with the same key as the given string */
bool	Channel::isInChannelUserList(std::string nick_name) {
	
	if (_user_list.count(nick_name))
		return true;
	return false;
}

/* returns the channel with the same key as the given string */
bool	Channel::isInChannelOperatorList(std::string nick_name) {
	
	if (_operator_list.count(nick_name))
		return true;
	return false;
}

/* returns the channel with the same key as the given string */
bool	Channel::isInChannelInviteList(std::string nick_name) {
	
	if (_invite_list.count(nick_name))
		return true;
	return false;
}
