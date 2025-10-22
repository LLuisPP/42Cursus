/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:49:03 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/22 19:30:08 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) {
}

HumanA::~HumanA(void) {}

void	HumanA::attack(void) {

	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
