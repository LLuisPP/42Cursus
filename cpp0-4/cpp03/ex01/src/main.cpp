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

#include "ScavTrap.hpp"

int	main(void) {

	ClapTrap   clap("Bonny");
    ScavTrap   trap("Clyde");   // <- ScavTrap

    clap.beRepaired(6);
    trap.beRepaired(7);

    clap.attack("Clyde");
    trap.takeDamage(20);

    // ScavTrap attacks with his stats (HP=100, EN=50, ATK=20)
    trap.attack("Bonny");
    clap.takeDamage(20);

    // Guard mode activated: Can't attack while active
    trap.guardGate();
    trap.attack("Bonny");
    trap.guardGate();
    trap.attack("Bonny");
	
	clap.attack("Clyde");
	trap.takeDamage(20);
	
	trap.attack("Bonny");
	clap.takeDamage(20);
	
	clap.attack("Clyde");
	trap.takeDamage(20);
	
	trap.attack("Bonny");
	clap.takeDamage(20);

	clap.attack("Clyde");
	trap.takeDamage(20);
	
	trap.attack("Bonny");
	clap.takeDamage(20);

	clap.attack("Clyde");
	trap.takeDamage(50);
	clap.beRepaired(5000);
	trap.attack("Bonny");

	clap.takeDamage(5);
	trap.beRepaired(5000);
	
	clap.attack("Clyde");
	trap.attack("Bonny");

	return (0);
}
