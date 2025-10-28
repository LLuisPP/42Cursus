/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:35:07 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/28 09:01:35 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void): _attack(0), _energy(10), _health(10) {
	
	std::cout << G << "ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name): _attack(5), _energy(10), _health(10) {
	
	_name = name;
	std::cout << "ClapTrap " << W << name << G << " created" << RES << " !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	
	*this = copy;
	std::cout << "ClapTrap " << Y << _name << RES << " created !" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {

	_name = copy._name;
	_health = copy._health;
	_energy = copy._energy;
	_attack = copy._attack;
	std::cout << PP << "ClapTrap " << Y << _name << PP << " copy assigned" << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string &target) {

	if (_energy > 0 && _health > 0) {
		_energy--;
		std::cout << "ClapTrap " << B << _name << RES << " attacks " << PP << target << RES << "," << OR << " causing " << _attack << RES << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << W << _name << Y << " can't attack!" << RES << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {

	if (_health > 0) {
		_health -= amount;
		std::cout << "ClapTrap " << PP << _name << R << " takes " << amount << RES << " points of damage" << std::endl;
		if (_health < 0)
			std::cout << "ClapTrap " << Y << _name << R << " is dead" << RES << std::endl;
	}
	else
		std::cout << "ClapTrap " << Y << _name << R << " is dead" << RES << std::endl;
}

void	ClapTrap::beRepaired(unsigned int health) {

	if (_energy > 0 && _health > 0) {
		_energy--;
		_health += health;
		std::cout << "ClapTrap " << _name << " gains " << G << health << " points " << RES << "of health" << RES << std::endl;
	}
}

ClapTrap::~ClapTrap (void) {

	std::cout << "ClapTrap " << GY <<_name << R << " destroyed !!" << RES << std::endl;
}