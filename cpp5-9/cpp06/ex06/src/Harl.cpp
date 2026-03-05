/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:45:11 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/23 18:49:47 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl (void) {}

Harl::~Harl(void) {}

void	Harl::debug(void) {
	std::cout << GREEN << "[DEBUG]:" << RESET << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
};

void	Harl::info(void) {
	std::cout << CYAN << "[INFO]:" RESET << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
};

void	Harl::warning(void) {
	std::cout << YELLOW << "[WARNING]:" << RESET << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
};

void	Harl::error(void) {
	std::cout << RED << "[ERROR]:" << RESET << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
};

void Harl::complain(std::string level) {

	std::string level_[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;

	while (i < 4) {
		if (level == level_[i])
			break;
		i++;
	}
	switch (i) {
		case 0:
			debug();
			// FALLTHROUGH
		case 1:
			info();
			// FALLTHROUGH
		case 2:
			warning();
			// FALLTHROUGH
		case 3:
			error();
			break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	};
};