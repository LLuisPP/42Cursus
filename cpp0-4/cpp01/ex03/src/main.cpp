/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:42:00 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/22 19:55:03 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main(int argc, char **argv) {

	if (argc != 1) {
		std::cout << "No arguments needed !" << std::endl;
	}
	{
		Weapon	club = Weapon("machine gun");

		HumanA	julius("Julius", club);
		julius.attack();
		club.setType("laser rifle");
		julius.attack();
	}
	{
		Weapon	oneHand = Weapon("chainsaw");
		Weapon	axe = Weapon("axe");

		HumanB	mia("mia");
		mia.attack();
		mia.setWeapon(&oneHand);
		mia.attack();
		oneHand.setType("katana");
		mia.attack();
		mia.setWeapon(&axe);
		mia.attack();
	}

	return (0);
}
