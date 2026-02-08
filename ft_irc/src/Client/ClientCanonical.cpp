/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClientCanonical.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:28:47 by lprieto-          #+#    #+#             */
/*   Updated: 2026/02/01 14:56:11 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

/* *********************** Canonical Forms *********************** */

Client::Client(): _fd(-1), _user_name("*"), _nickname("*"), _realname(""), _state(NOT_AUTHENTICATED)
{}; // Default constructor

Client::~Client() {
  
  if (_fd > 0) {
    std::cout << _fd << "Client destructor called" << std::endl;
  };
};

Client::Client(const Client *copy) {
  *this = copy;
};

Client &Client::operator=(const Client& copy) {

  if (this != &copy) {
    _fd = copy._fd;
    _user_name = copy._user_name;
    _nickname = copy._nickname;
  }
  return (*this);
};

Client::Client(int _fd): _fd(_fd), _user_name("*"), _nickname("*"), _realname(""), _state(NOT_AUTHENTICATED)
{};
