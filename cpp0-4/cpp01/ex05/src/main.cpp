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
	}

	std::cout << "[DEBUG]:" << std::endl;
	harl.complain("debug");
	std::cout << "[INFO]:" << std::endl;
	harl.complain("info");
	std::cout << "[WARNING]:" << std::endl;
	harl.complain("warning");
	std::cout << "[ERROR]:" << std::endl;
	harl.complain("error");

	return (0);
}
