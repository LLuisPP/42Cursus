/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragFrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 09:51:12 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/31 09:54:29 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap {

	private:
		bool	_guard;
	public:
		FragTrap(void);
		FragTrap(const FragTrap &copy);
		FragTrap &operator=(const FragTrap &copy);
		~FragTrap(void);

		FragTrap(const std::string name);
		
		void	highFiveGuys(void);
};

#endif
