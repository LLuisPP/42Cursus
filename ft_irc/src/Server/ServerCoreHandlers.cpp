/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerCoreHandlers.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:18:55 by lgracia-          #+#    #+#             */
/*   Updated: 2026/02/02 17:09:54 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

/* *********************** Signal ********************************************/

bool Server::_signal = false;

void Server::signalHandler(int signum) {
	
	(void)signum;
	std::cout << "\nSignal received! Shutting down server..." << std::endl;
	Server::_signal = true;
}

/* *********************** Handle new Connection ****************************/

void Server::handleNewConnection() {

	int fd = acceptSocket();
	if (fd < 0)
		return;

	pollfd p;
	p.fd = fd;
	p.events = POLLIN;
	p.revents = 0;

	_pfds.push_back(p);
	_buffers[fd] = "";

	std::cout << "New client: FD = " << fd << std::endl;
}
/* *********************** handleNewConnection ***********************
 * FUNCTION:
 *    Accepts a new incoming connection from the listening socket
 *    using accept(). If the connection is valid, the new client file
 *    descriptor is added to the _pfds vector to be monitored by poll(),
 *    and its partial buffer is initialized.
 *
 * INPUT: None. Internally uses:
 *      _socket_fd : server socket in listen mode
 *
 * OUTPUT: None. Effects:
 *      - Adds a new pollfd to the _pfds vector
 *      - Creates an empty buffer in _buffers[fd]
 * ************************************************************** */

void Server::handleClientRead(size_t i) {

	int fd = _pfds[i].fd;
	char buf[1024];
	int n = recv(fd, buf, sizeof(buf), 0);

	if (n <= 0) {
		disconnectClient(i);
		return ;
	}

	_buffers[fd] += std::string(buf, n);

	size_t pos;
	while ((pos = _buffers[fd].find("\n")) != std::string::npos) {

		std::string line = _buffers[fd].substr(0, pos);
		_buffers[fd].erase(0, pos + 1);

		if (!_client_list_fd.count(fd))
			_client_list_fd[fd] = Client(fd);

		parseInit(line, &_client_list_fd[fd]);
		if (_client_list_fd.count(fd) && _client_list_fd[fd].getState() == 6)
			_client_list_name[_client_list_fd[fd].getNickname()] = &_client_list_fd[fd];
	}
}
/* *********************** handleClientRead ***********************
 * FUNCTION:
 *    Handles reading data from a client whose file descriptor
 *    has been marked as ready for reading by poll().
 *
 *    - Uses recv() to read data in non-blocking mode.
 *    - If n <= 0 → the client has disconnected, disconnectClient() is called.
 *    - If data is received, it is appended to the partial buffer _buffers[fd].
 *    - Extracts complete lines terminated by '\n'.
 *    - For each complete line received: → prints the line on the server →
 *      sends an echo message back to the client (test)
 *
 * INPUT: size_t i
 *      Index within _pfds of the client sending data.
 *
 * OUTPUT: None. Effects:
 *      - Processes input buffers
 *      - May send data to the client
 *      - May disconnect the client if recv() fails
 * ************************************************************** */

void Server::disconnectClient(size_t i, std::string msg) {

	int fd = _pfds[i].fd;
	std::cout << "Client disconnected FD=" << fd << std::endl;

	if (_client_list_fd.count(fd)) { 	// Clean up client lists
		Client *clientptr = &_client_list_fd[fd];
		std::string nick = clientptr->getNickname();
		std::string user = clientptr->getUserName();
		std::string reason = msg.empty() ? "Disconnected" : msg;
		std::string quitMsg = ":" + nick + "!" + user + "@localhost QUIT :" + reason + "\r\n";

		std::map<std::string, Channel>::iterator it = _channel_list.begin();
		while (it != _channel_list.end()) {
				Channel &chan = it->second;

				if (chan.isInChannelUserList(nick))
					chan.spreadMsg(quitMsg);
				chan.deleteUser(clientptr);
				chan.deleteUserOperator(clientptr);
				chan.deleteUserInvite(clientptr);
				
				chan.usersLeft();
	
				if (chan.getUserList().empty()) {
						std::map<std::string, Channel>::iterator to_erase = it;
						std::string chanName = to_erase->first;
						++it;
						_channel_list.erase(to_erase); 
						std::cout << "Channel " << chanName << " deleted (empty after disconnect)." << std::endl;
				} else
					++it;	
		}
		
		if (!nick.empty() && _client_list_name.count(nick))
			_client_list_name.erase(nick);
			
		_client_list_fd.erase(fd);
	}

	close(fd); 
	_buffers.erase(fd);
	_pfds.erase(_pfds.begin() + i);
}
/* *********************** Disconnect client ***********************
 * FUNCTION:
 *    Closes and completely removes a client from the server.
 *
 *    - Retrieves the client fd from _pfds[i]
 *    - Closes the socket using close(fd)
 *    - Removes its partial buffer from _buffers
 *    - Removes it from the _pfds vector so poll() stops monitoring it
 *
 * INPUT: size_t i
 *      Index within _pfds of the client to be removed.
 *
 * OUTPUT: None. Effects:
 *      - Client properly disconnected and cleaned up
 * ************************************************************** */
