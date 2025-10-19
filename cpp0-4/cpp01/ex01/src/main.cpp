/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:14:42 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/19 20:19:46 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv) {

	Zombie	*horde;
	int		zombies;

	if (argc != 1 && argv) {
		std::cout << "No argumentz needed... brainzzz" << std::endl;
		return (1);
	}
	zombies = 5;
	std::cout << zombieHorde(zombies, "Zombie");
	for (int i = 0; i < zombies; i++) {
		horde[i].announce();
	};
	delete [] horde;
	return (0);
}
