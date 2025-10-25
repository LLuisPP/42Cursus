/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed2.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:30:08 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/25 15:03:39 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed2.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _rawBits(0) {
	std::cout << G << "Default constructor" << RES << " called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << Y << "Copy constructor" << RES << " called" << std::endl;
	_rawBits = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << BB << "Copy assignment operator" << RES << " called" << std::endl;
	_rawBits = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << BR << "Destructor" << RES << " called" << std::endl;
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

/* ************************** CONSTRUCTORS FOR **************************** */

Fixed::Fixed(float f) {

	std::cout << BY << "Float constructor" << RES << " called" << std::endl;
	_rawBits = (float)(roundf(f * (1 << _fractionalBits)));
}

Fixed::Fixed(int n) {

	std::cout << BY << "Int constructor" << RES << " called" << std::endl;
	_rawBits = n << _fractionalBits;
}


/* ************************** CONVERSORS ********************************** */

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

/* ************************** ADITTIONAL OPERATORS ************************ */

/* *********    COMPATARION OPERATORS      ********** */

bool	Fixed::operator<(Fixed const &other) const { return (_rawBits < other._rawBits); }
bool	Fixed::operator>(Fixed const &other) const { return (_rawBits > other._rawBits); }
bool	Fixed::operator<=(Fixed const &other) const { return (_rawBits <= other._rawBits); }
bool	Fixed::operator>=(Fixed const &other) const { return (_rawBits >= other._rawBits); }
bool	Fixed::operator==(Fixed const &other) const { return (_rawBits == other._rawBits); }
bool	Fixed::operator!=(Fixed const &other) const { return (_rawBits != other._rawBits); }

/* *********    ARITHMETIC OPERATORS      ********** */

Fixed	Fixed::operator+(Fixed const &other) const { return (this->toFloat() + other.toFloat()); }
Fixed	Fixed::operator-(Fixed const &other) const { return (this->toFloat() - other.toFloat()); }
Fixed	Fixed::operator*(Fixed const &other) const { return (this->toFloat() * other.toFloat()); }
Fixed	Fixed::operator/(Fixed const &other) const { return (this->toFloat() / other.toFloat()); }
	
/* *********    ++/-- OPERATORS      ********** */
Fixed	&Fixed::operator++(void) { ++_rawBits; return (*this); }  // preincrement
Fixed	Fixed::operator++(int) { Fixed	tmp(*this); ++_rawBits;	return (tmp); } // postincrement
Fixed	&Fixed::operator--(void) { --_rawBits;	return (*this); } // predecrement
Fixed	Fixed::operator--(int) { Fixed	tmp(*this); --_rawBits;	return (tmp); } // postdecrement

/* *********    max/min OPERATORS      ********** */
Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a.toFloat() > b.toFloat())
		return(b);
	return (a);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a.toFloat() > b.toFloat())
		return(a);
	return (b);
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b) {
	if (a.toFloat() > b.toFloat())
		return(b);
	return (a);
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b) {
	if (a.toFloat() > b.toFloat())
		return(a);
	return (b);
}
