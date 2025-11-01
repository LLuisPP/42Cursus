/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:08:25 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/01 13:08:26 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {

	std::cout << GY << "WrongAnimal" << G << " created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {

	_type = copy._type;
	std::cout << GY << "WrongAnimal" << G << " created" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &copy) {

	_type = copy._type;
	std::cout << GY << "WrongAnimal" << G << " created" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal(void) {

	std::cout << GY << "WrongAnimal" << R << " destroyed" << RES << std::endl;
}

void	WrongAnimal::makeSound(void) {

	std::cout << GY << "* Wrong Silence *" << RES << std::endl;
}
