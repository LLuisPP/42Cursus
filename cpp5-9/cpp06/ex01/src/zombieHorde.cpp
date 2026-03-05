/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:11:23 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/19 20:13:43 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name) {

	Zombie	*horde;

	horde = new Zombie[n];
	for(int i = 0; i < n; i++) {
		horde[i].setName(name);
	}
	return (horde);
}
