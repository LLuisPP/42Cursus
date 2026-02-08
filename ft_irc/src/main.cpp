/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:25:23 by lprieto-          #+#    #+#             */
/*   Updated: 2026/02/08 11:23:51 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

int main(int argc, char** argv) {

	get_monitoring(1, 0);
	
	if (argc != 3) {
		if (!argv[2] || argv[2][0] == '\0')
			return (std::cerr << "Usage: ./ircserv <port> <password> (password is compulsory)" << std::endl, 1);
		for (int i = 0; argv[2][i] != '\0'; i++)
		{
			if (argv[2][i] == ' ' || argv[2][i] == '\t' || argv[2][i] == '\r' || argv[2][i] == '\n')
				return (std::cerr << "Usage: forbidden character for password" << std::endl, 1);
		}
		if (argc == 4) {
			std::string str(argv[3]);
			if (!str.compare("parsing"))
				get_monitoring(1, 1);
			else
				return (std::cerr << "Usage: ./ircserv <port> <password>" << std::endl, 1);
		}
		else
			return (std::cerr << "Usage: ./ircserv <port> <password>" << std::endl, 1);
	}

	signal(SIGINT, Server::signalHandler);
	signal(SIGQUIT, Server::signalHandler);
	signal(SIGPIPE, SIG_IGN);
	
	try {
		Server  srv(argv[1], argv[2]);

		srv.createSocketFd();
		srv.bindSocket();
		srv.listenSocket();
		srv.initPoll();
		srv.runLoop();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}

	return (0);
}