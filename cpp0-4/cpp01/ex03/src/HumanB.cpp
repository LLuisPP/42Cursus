/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:51:44 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/22 19:35:39 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {
}

HumanB::~HumanB(void) {}

void	HumanB::attack(void) {

	if(_weapon) {
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	}
	else {
		std::cout << _name << " has no weapon" << std::endl;
	}
}

void	HumanB::setWeapon(Weapon *weapon) {

	_weapon = weapon;
}

