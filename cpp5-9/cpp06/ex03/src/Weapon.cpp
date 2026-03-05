/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:48:11 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/22 19:27:10 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
}

Weapon::Weapon(std::string type) {

	_type = type;
}

Weapon::~Weapon() {
}

void	Weapon::setType(std::string type) {
	_type = type;
}

const std::string& Weapon::getType(void) const {

	return (this->_type);
}
