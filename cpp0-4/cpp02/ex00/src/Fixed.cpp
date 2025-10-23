/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:29:58 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/23 19:51:36 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_frac = 8;

Fixed::Fixed(void)
{
	std::cout << "Fixed: Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Fixed: Copy constructor called" << std::endl;
	_value = copy.getRawBits();
}

Fixed&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Fixed: Assign constructor called" << std::endl;
	_value = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Fixed: Destroyed" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "Fixed: getRawBits called" << std::endl;
	return _value;
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}
