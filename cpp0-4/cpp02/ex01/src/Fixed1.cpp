/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed2.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:09:53 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/25 11:37:00 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed1.hpp"

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

/* ************************** CONSTRUCTORS FOR ********************************* */

Fixed::Fixed(float f) {

	std::cout << BY << "Float constructor" << RES << " called" << std::endl;
	_rawBits = (float)(roundf(f * (1 << _fractionalBits)));
}

Fixed::Fixed(int n) { 

	std::cout << BY << "Int constructor" << RES << " called" << std::endl;
	_rawBits = n << _fractionalBits;
}


/* ************************** CONVERSORS *********************************** */

float	Fixed::toFloat(void) const {
	
	float result = (float)_rawBits / (1 << _fractionalBits);
	return (result);
}

int	Fixed::toInt(void) const {

	int	result = _rawBits >> _fractionalBits;
	return (result);
}

/* ************************** OPERATOR ************************************ */

std::ostream	&operator << (std::ostream &outstr, Fixed const &fix) {

	outstr << fix.toFloat();
	return (outstr);
}

