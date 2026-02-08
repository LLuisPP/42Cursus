/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerCanonical.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:28:47 by lprieto-          #+#    #+#             */
/*   Updated: 2026/02/01 15:07:47 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

/* *********************** Canonical Forms *********************** */

Server::Server(): _socket_fd(-1), _server_up(0), _port(6667), _ip_address("127.0.0.1"), _connection_nbr(0), _password("1234")
{};

Server::~Server() {

  if (_socket_fd != -1) {
    close(_socket_fd);
  };

  for (std::map<int, Client>::iterator it = _client_list_fd.begin(); it != _client_list_fd.end(); ++it) // Close all client sockets
  {
    close(it->first);
  }
  _client_list_fd.clear();
};

Server::Server(const Server &copy) {
  
  *this = copy;
};

Server  &Server::operator=(const Server &copy) {

  if (this != &copy) {
    _socket_fd = copy._socket_fd;
    _server_up = copy._server_up;
    _port = copy._port;
    _ip_address = copy._ip_address;
    _connection_nbr = copy._connection_nbr;
  }
  return (*this);
};

Server::Server(std::string port, std::string password): _socket_fd(-1), _server_up(0), _ip_address("127.0.0.1"), _connection_nbr(0), _password(password) {
  
  size_t i = 0;
  while (port.at(i) && isdigit(port.at(i))) {
    if (i == port.size() - 1)
      break;
    i++;
  }
  if (i != port.size() - 1)
    throw std::invalid_argument("Error: Invalid port");
  _port = std::atoi(port.c_str());
  if (_port <= 3000 || _port > 65535)
    throw std::range_error("Error: Port out of range");
};
