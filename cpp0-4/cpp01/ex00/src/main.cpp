/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 07:50:50 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/19 08:21:02 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv) {

	Zombie	*zombie;

	if(argc != 1 && argv) {
		std::cerr << "Zombie requirezz NO argumentzz..." << std::endl;
		return (1);
	}
	(void)argv;

	zombie = newZombie("Zombie 1");
	zombie->announce();
	randomChump("Zombie 2");
	zombie->announce();

	delete zombie;
	return (0);
}
