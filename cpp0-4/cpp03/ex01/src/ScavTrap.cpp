/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:03:42 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/29 10:25:35 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) ClapTrap(), _guard(false) {

	_health = 100;
	_energy = 50;
	_attack = 20;
	std::cout << "ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name), _guard(false) {

	_health = 100;
	_energy = 50;
	_attack = 20;
	std::cout << "ScavTrap " << _name << " created" << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy), _guard(false) {

	*this = copy;
	std::cout << "ScavTrap " << _name << " copy created" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &copy) {

	_name = copy._name;
	_health = copy._health;
	_energy = copy._energy;
	_attack = copy._attack;
	std::cout << "ScavTrap " << _name << " copy assigned" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void) {

	std::cout << "ScavTrap " << _name << " destroyed !!" << std::endl;	
}

void	ScavTrap::attack(const std::string &target) {

	if (_energy > 0 && _health > 0 && !_guard) {
		_energy--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing" << _attack << " points of damage" << std::endl;	
	}
	else
		std::cout << "ScavTrap " << _name << " can't attack!" << std::endl;	
}

void	ScavTrap::guardGate(void) {

	_guard = !_guard;
	if (_guard)
		std::cout << "ScavTrap " << _name << " is in guard" << std::endl;	
	else
		std::cout << "ScavTrap " << _name << " leaves the guard" << std::endl;	
}



