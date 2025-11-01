/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:03:42 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/01 10:25:35 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap(), _guard(false) {

	_health = 100;
	_energy = 50;
	_attack = 20;
	std::cout << GY << "ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _guard(false) {

	_health = 100;
	_energy = 50;
	_attack = 20;
	std::cout << GY << "ScavTrap " << B << _name << G << " created !!" << RES << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy), _guard(false) {

	*this = copy;
	std::cout << GY << "ScavTrap " << B << _name << " copy created !!" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &copy) {

	_name = copy._name;
	_health = copy._health;
	_energy = copy._energy;
	_attack = copy._attack;
	std::cout << GY << "ScavTrap " << B << _name << RES << " copy assigned !!" << std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string &target) {
	
	if (_energy > 0 && _health > 0 && !_guard) {
		_energy--;
		std::cout << GY << "ScavTrap " << B << _name << RES << " attacks " << C << target << RES << "," << R << " causing " << _attack << RES << " points of damage" << std::endl;	
	}
	else
	std::cout << GY << "ScavTrap " << B << _name << RES << " can't attack!" << std::endl;	
}

void	ScavTrap::guardGate(void) {

	_guard = !_guard;
	if (_guard)
		std::cout << GY << "ScavTrap " << B << _name << G << " is in guard" << std::endl;	
	else
		std::cout << GY << "ScavTrap " << B << _name << OR << " leaves the guard" << std::endl;	
}

ScavTrap::~ScavTrap(void) {

	std::cout << GY << "ScavTrap " << B << _name << R << " destroyed !!" << std::endl;	
}

