/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 22:00:00 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/10 22:00:00 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : stringValue(""), intValue(0) {}

Data::Data(const Data &src) {
	*this = src;
}

Data &Data::operator=(const Data &rhs) {
	if (this != &rhs) {
		this->stringValue = rhs.stringValue;
		this->intValue = rhs.intValue;
	}
	return (*this);
}

Data::~Data() {}
