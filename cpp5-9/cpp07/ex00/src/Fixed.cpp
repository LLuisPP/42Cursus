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

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _rawBits(0) {
	std::cout << G << "Default constructor" << RES " called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << Y << "Copy constructor" << RES << " called" << std::endl;
	_rawBits = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << BB << "Copy assignment operator" << RES " called" << std::endl;
	_rawBits = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << BR << "Destructor" << RES " called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << PP << "getRawBits member function" << RES << " called" << std::endl;
	return _rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}
