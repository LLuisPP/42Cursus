/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:04:51 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/19 20:10:47 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	name = "Zombie William";
	std::cout << name << ": created" << std::endl;
}

Zombie::Zombie(std::string name) {
	this->name = name;
	std::cout << name << ": created" << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << name << ": destroyed" << std::endl;
}

void Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string newName) {
	this->name = newName;
	std::cout << name << ": Set name to " << this->name << std::endl;
}
