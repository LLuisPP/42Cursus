/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClientGetAndSet.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 19:04:08 by lgracia-          #+#    #+#             */
/*   Updated: 2026/02/01 15:03:01 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

/* *********************** Getters *********************** */

int         Client::getFd() const { return _fd; }
std::string Client::getNickname() const { return _nickname; }
std::string Client::getUserName() const { return _user_name; }
std::string Client::getRealName() const { return (_realname); }
StatusLevel Client::getState() const { return (_state); }

/* *********************** Setters *********************** */

void    Client::setNickname(std::string nick) { _nickname = nick; }
void    Client::setUserName(std::string user) { _user_name = user; }
void    Client::setRealName(std::string real) { _realname = real; }
void    Client::setState(StatusLevel state) { _state = state; }
void    Client::setFd(int fd) { _fd = fd; }