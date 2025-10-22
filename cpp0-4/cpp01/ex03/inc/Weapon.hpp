/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:52:37 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/22 19:39:30 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {

	private:
		std::string _type;
	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
		std::string	getType(void);
		void		setType(std::string type);
};

#endif
