/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 09:50:01 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/31 09:50:57 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	_health = 100;
	_energy = 100;
	_attack = 30;
	std::cout << W << "FragTrap" << G << " created !!!" << RES << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name), _guard(false)
{
	_health = 100;
	_energy = 100;
	_attack = 30;
	std::cout << W << "FragTrap " << PP << _name << G << " created !!!" << RES << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy), _guard(false)
{
	*this = copy;
	std::cout << W << "FragTrap " << _name << " copy created!" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &copy)
{
	_name = copy._name;
	_health = copy._health;
	_energy = copy._energy;
	_attack = copy._attack;
	_guard = copy._guard;
	std::cout << W << "FragTrap " << _name << " copy assigned!" << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << W << "FragTrap " << _name << " destroyed!" << std::endl;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << W << "FragTrap " << PP << _name << G << " high five!" << RES << std::endl;
}
