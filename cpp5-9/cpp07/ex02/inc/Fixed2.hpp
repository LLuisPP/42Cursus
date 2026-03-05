/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed2.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 09:59:15 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/25 14:33:16 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED2_HPP
# define FIXED2_HPP

// Color macros:
#define RES	"\033[0m"
#define BGY	"\033[1;90m"
#define BR	"\033[1;91m"
#define BGR	"\033[1;92m"
#define BY	"\033[1;33m"
#define BB	"\033[1;94m"
#define BC	"\033[1;96m"
#define BW	"\033[1;97m"
#define GY	"\033[0;90m"
#define R	"\033[0;91m"
#define G	"\033[0;92m"
#define Y	"\033[0;93m"
#define B	"\033[0;94m"
#define C	"\033[0;96m"
#define W	"\033[0;97m"
#define PP	"\033[0;95m"
#define BD	"\033[1m"
#define OR	"\033[38;5;214m"
// macros

#include <iostream>
#include <cmath>

class	Fixed {

	private:
		int					_rawBits;
		static const int	_fractionalBits;

	public:
		Fixed();
		Fixed (Fixed const &copy);
		Fixed& operator = (const Fixed &copy);
		~Fixed();
		// Orthodoxal Canonical Form

		Fixed(int n);
		Fixed(float f);
		float	toFloat(void) const;
		int		toInt(void) const;

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		/* *** COMPARE OPERATORS ** */

		bool	operator<(Fixed const &other) const;
		bool	operator>(Fixed const &other) const;
		bool	operator<=(Fixed const &other) const;
		bool	operator>=(Fixed const &other) const;
		bool	operator==(Fixed const &other) const;
		bool	operator!=(Fixed const &other) const;
		
		/* *** ARITHMETIC OPERATORS ** */

		Fixed	operator+(Fixed const &other) const;
		Fixed	operator-(Fixed const &other) const;
		Fixed	operator*(Fixed const &other) const;
		Fixed	operator/(Fixed const &other) const;
		
		// prefix
		Fixed	&operator++();
		Fixed	&operator--();
		// sufix
		Fixed	operator++(int);
		Fixed	operator--(int);

		/* *** MAX/MIN OPERATORS ** */

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(Fixed const &a, Fixed const &b);
		static const Fixed &max(Fixed const &a, Fixed const &b);

};

std::ostream &operator << (std::ostream &outstr, Fixed const &fix);

#endif
