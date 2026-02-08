/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerCore.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:28:47 by lprieto-          #+#    #+#             */
/*   Updated: 2026/02/01 16:45:31 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include <cerrno>

int Server::createSocketFd() {

	_socket_fd = socket(AF_INET, SOCK_STREAM, 0); /* AF_INET == IPv4, SOCK_STREAM == stream * TCP, 0 default protocol (TCP) */
	if (_socket_fd < 0) {
		std::cerr << "Error: cannot create socket\n";
		return (-1);
	};

	int opt = 1;
	setsockopt(_socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt,	sizeof(opt)); /* allows reusing a port that remains in TIME_WAIT */
	fcntl(_socket_fd, F_SETFL, O_NONBLOCK); /* sets the socket to non-blocking mode, important to avoid blocking read, recv, send, accept, etc. calls */
	return (_socket_fd);
}
/* *********************** createSocketFd ***********************
 * FUNCTION:
 *    Creates the main TCP server socket, enables SO_REUSEADDR
 *    and configures it in non-blocking mode (O_NONBLOCK).
 *
 * INPUT: None. Uses the internal attributes of the class:
 *      _socket_fd  (overwritten)
 *
 * OUTPUT: int
 *      >= 0 : file descriptor of the created socket
 *      -1   : error while creating the socket
 * ************************************************************** */

bool Server::bindSocket() {

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr)); /* memory initalized to 0 for security */

	addr.sin_family = AF_INET;    /* IPv4 structure */
	addr.sin_port = htons(_port); /* port number */
	addr.sin_addr.s_addr = inet_addr(_ip_address.c_str()); /* declared IP as a binary */

	if (bind(_socket_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		std::cerr << "Error: cannot bind socket\n";
		return (false);
	}
	return (true);
};
/* *********************** bindSocket ***********************
 * FUNCTION:
 *    Binds the main socket to an IP address and a port using
 *    the sockaddr_in structure configured with IPv4.
 *
 * INPUT: None. Uses the internal attributes:
 *      _socket_fd   : previously created socket
 *      _ip_address  : IP address in string format
 *      _port        : server port
 *
 * OUTPUT: bool
 *      true  : bind() successfully performed
 *      false : error while binding the socket to IP/port
 * ************************************************************** */

bool Server::listenSocket() {

	if (listen(_socket_fd, 10) < 0) { /* sets the socket to passive listening state */
		std::cerr << "Error: cannot listen\n";
		return (false);
	};
	return (true);
};
/* *********************** listenSocket ***********************
 * FUNCTION:
 *    Puts the server socket into passive mode, creating a queue of
 *    pending connections to accept clients, 10 as maximum in this case.
 *
 * INPUT: None. Uses:
 *      _socket_fd : already bound socket
 *
 * OUTPUT: bool
 *      true  : socket successfully enters listen mode
 *      false : listen() fails
 * ************************************************************** */

int	Server::acceptSocket() {

	struct sockaddr_in client;
	socklen_t len = sizeof(client);
	int client_fd = accept(_socket_fd, (struct sockaddr *)&client, &len);
	if (client_fd < 0)
		return (-1);
	fcntl(client_fd, F_SETFL, O_NONBLOCK);
	return (client_fd);
}
/* *********************** acceptSocket ***********************
 * FUNCTION:
 *    Accepts a new incoming connection from the listen queue and
 *    returns a new file descriptor for the client.
 *
 * INPUT: None. Uses:
 *      _socket_fd : socket currently in listen mode
 *
 * OUTPUT: int
 *      >= 0 : file descriptor of the newly accepted client
 *      -1   : error in accept() (for example, no pending connections)
 * ************************************************************** */

void	Server::initPoll() {

	pollfd pfd;
	pfd.fd = _socket_fd;
	pfd.events = POLLIN;
	pfd.revents = 0;

	_pfds.push_back(pfd);
}
/* *********************** initPoll ***********************
 * FUNCTION:
 *    Initializes the poll structure by adding the listening socket
 *    (server socket) to the _pfds vector so it can be monitored by poll().
 *
 * INPUT: None. Uses the internal attribute:
 *      _socket_fd : listening socket file descriptor
 *
 * OUTPUT: None. Modifies:
 *      _pfds : adds the initial pollfd entry for the server
 * ************************************************************** */

void	Server::runLoop() {

	while (Server::_signal == false) {

		int ret = poll(&_pfds[0], _pfds.size(), -1);
		if (ret < 0) {
			if (errno == EINTR) // Interrupted system call (signal received)
				continue;
			std::cerr << "poll() error\n";
			break; // Exit loop on error
		}
		for (size_t i = 0; i < _pfds.size(); i++) {

			if (i == 0 && (_pfds[i].revents & POLLIN)) { // new client
				handleNewConnection();
			}
			else if (_pfds[i].revents & POLLIN) { // Reading existing client
				handleClientRead(i);
			}
			else if (_pfds[i].revents & (POLLHUP | POLLERR | POLLNVAL)) { // Disconection or error
				disconnectClient(i);
			}
		}
	}

	std::cout << "Cleaning up connections..." << std::endl; // Cleanup on shutdown
	for (size_t i = 0; i < _pfds.size(); i++) {
		int fd = _pfds[i].fd;
		if (i > 0) { // Skip listener (index 0) for message
			std::string msg = "ERROR :Server shutting down\r\n";
			send(fd, msg.c_str(), msg.size(), 0);
		}
		std::cout << "Closing FD " << fd << std::endl;

		// Force RST to ensure client detects disconnection immediately
		struct linger l;
		l.l_onoff = 1;
		l.l_linger = 0;
		setsockopt(fd, SOL_SOCKET, SO_LINGER, &l, sizeof(l));

		shutdown(fd, SHUT_RDWR);
		close(fd);
	}
	_pfds.clear();
	_buffers.clear();
	_client_list_fd.clear();
}
/* *********************** runLoop (POLL MAIN LOOP) ***********************
 * FUNCTION:
 *    Main server loop. Handles all communication using a single poll(),
 *    as required by the subject.
 *
 *    Behavior:
 *      - poll() waits for events on all fds in _pfds
 *      - If index 0 has POLLIN → new incoming connection
 *      - If a client fd has POLLIN → pending data → handleClientRead(i) is called
 *      - If POLLHUP, POLLERR or POLLNVAL appear → dead client → disconnectClient(i) is called
 *
 * INPUT: None.
 *
 * OUTPUT: None. Infinite loop that keeps the server running.
 * ************************************************************** */
