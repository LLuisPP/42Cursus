/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:25:03 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/23 19:53:43 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed {

	private:
		int					_value;
		static const int	_frac;
	public:
		Fixed();
		~Fixed();

		Fixed (Fixed const &copy);
		Fixed& operator = (const Fixed &copy);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
