/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:31:15 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/28 09:04:11 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {

	ClapTrap	clap("Bonny");
	ClapTrap	trap("Clyde");


	clap.beRepaired(6);
	trap.beRepaired(7);
	
	clap.attack("Clyde");
	trap.takeDamage(5);
	
	trap.attack("Bonny");
	clap.takeDamage(5);
	
	clap.attack("Clyde");
	trap.takeDamage(5);
	
	trap.attack("Bonny");
	clap.takeDamage(5);

	clap.attack("Clyde");
	trap.takeDamage(11);
	
	trap.attack("Bonny");
	clap.takeDamage(2147483648u);

	
	clap.attack("Clyde");
	trap.takeDamage(50);
	trap.beRepaired(5000);
	trap.attack("Bonny");

	clap.takeDamage(5);
	trap.beRepaired(5000);
	
	clap.attack("Clyde");
	trap.attack("Bonny");

	return (0);
}
