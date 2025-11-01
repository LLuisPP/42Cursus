/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:08:25 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/01 13:08:26 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal() {

	_type = "Wrong Cat";
	std::cout << GY << "WrongCat" << G << " created" << RES << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal() {

	_type = copy._type;
	std::cout << GY << "WrongCat" << G << " created" << RES << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &copy) {

	_type = copy._type;
	std::cout << GY << "WrongCat" << G << " created" << RES << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void) {

	std::cout << GY << "WrongCat" << R << " destroyed" << RES << std::endl;
}

void	WrongCat::makeSound(void) {

	std::cout << "* Wrong" << PP << " meeeeeeew *" << std::endl;
}
