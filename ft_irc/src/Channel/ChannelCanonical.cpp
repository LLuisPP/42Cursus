/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChannelCanonical.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:28:47 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/23 17:55:20 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

/* *********************** Canonical Forms *********************** */

Channel::Channel()
 : _channel_name("Channel"), _limit_n_users(MAX_CHANNEL), _key(""), _mode_i(false), _mode_t(false), _mode_k(false), _mode_l(false), _topic("")
{}

Channel::~Channel() {
}

Channel::Channel(const Channel& copy) {
    
    *this = copy;
}

Channel& Channel::operator=(const Channel& copy) {
    
    if (this != &copy) {
        _channel_name = copy._channel_name;
        _user_list = copy._user_list;
        _operator_list = copy._operator_list;
        _limit_n_users = copy._limit_n_users;
        _key = copy._key;
        _mode_i = copy._mode_i;
        _mode_t = copy._mode_t;
        _mode_k = copy._mode_k;
        _mode_l = copy._mode_l;
        _topic = copy._topic;
    }
    return (*this);
}

Channel::Channel(std::string name, Client* client)
 : _channel_name(name), _limit_n_users(MAX_CHANNEL), _key(""), _mode_i(false), _mode_t(false), _mode_k(false), _mode_l(false),_topic("")
{
    _user_list[client->getNickname()] = client;
    _operator_list[client->getNickname()] = client;
}
