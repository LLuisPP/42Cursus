/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:39:15 by lgracia-          #+#    #+#             */
/*   Updated: 2026/02/03 18:08:51 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

/* monitors if the flag parsing to monitor the in and out */
bool	get_monitoring(bool modify, bool status) {

	static bool	monitoring;

	if (modify)
		monitoring = status;
	return (monitoring);
}

/* Separate the string by spaces */
std::vector<std::string> splitCommand(std::string input) {
	
	std::vector<std::string> args;
	std::string token;
	
	size_t pos = input.find("\r");
	if (pos != std::string::npos) input.erase(pos);
	pos = input.find("\n");
	if (pos != std::string::npos) input.erase(pos);

	std::stringstream ss(input);
	while (getline(ss, token, ' ')) {
		if (!token.empty()) args.push_back(token);
	}
	return (args);
}

/* Convert ints into strings */ 
std::string	itoa(int i) {

	std::stringstream ss;
	if (i < 10)
		ss << "00";
	else if (i < 100)
		ss << "0";
	ss << i;
	return ss.str();
}

/* RED LOG: Incoming Messages (from Client to Server) */
void	logInput(int fd, std::string msg) {

	if (msg.length() > 500) msg = msg.substr(0, 500) + "...";
	std::cout << WHITE << "<" << fd << "> " << RED << "<< " << msg << RESET << std::endl;
}

/* GREEN LOG: Outgoing Messages (from Server to Client) */
void	logOutput(int fd, std::string msg) {

	std::string clean = msg;
	if (clean.size() >= 2 && clean.substr(clean.size()-2) == "\r\n") // Visual cleanup: we remove the final \r\n, 1 LINE
		clean.erase(clean.size() - 2);
	std::cout << WHITE << "<" << fd << "> " << GREEN << ">> " << clean << RESET << std::endl;
}