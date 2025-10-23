/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 08:49:39 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/23 11:52:40 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv) {

	Harl	harl;
	
	if (argc != 1) {
		std::cout << "No arguments required !" << std::endl;
		return (1);
	}

	std::cout << GREEN << "[DEBUG]:" << RESET << std::endl;
	harl.complain("debug");
	std::cout << CYAN << "[INFO]:" RESET << std::endl;
	harl.complain("info");
	std::cout << YELLOW << "[WARNING]:" << RESET << std::endl;
	harl.complain("warning");
	std::cout << RED << "[ERROR]:" << RESET << std::endl;
	harl.complain("error");
	std::cout << RED << "[BAD_LEVEL]:" << RESET << std::endl;
	harl.complain("bad_level");
	return (0);
}
