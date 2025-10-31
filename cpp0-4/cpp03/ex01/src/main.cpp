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

	ClapTrap   clap("Okto");
    ScavTrap   trap("Link");   // <- ScavTrap

    clap.beRepaired(6);
    trap.beRepaired(7);

    clap.attack("Link");
    trap.takeDamage(20);

    // ScavTrap attacks with his stats (HP=100, EN=50, ATK=20)
    trap.attack("Okto");
    clap.takeDamage(20);

    // Guard mode activated: Can't attack while active
    trap.guardGate();
    trap.attack("Okto");
    trap.guardGate();
    trap.attack("Okto");
	
	// Rest of the combat cycle from ex00
	clap.attack("Link");
	trap.takeDamage(20);
	
	trap.attack("Okto");
	clap.takeDamage(20);
	
	clap.attack("Link");
	trap.takeDamage(20);
	
	trap.attack("Okto");
	clap.takeDamage(20);

	clap.attack("Link");
	trap.takeDamage(20);
	
	trap.attack("Okto");
	clap.takeDamage(20);

	clap.attack("Link");
	trap.takeDamage(50);
	clap.beRepaired(5000);
	trap.attack("Okto");

	clap.takeDamage(5);
	trap.beRepaired(5000);
	
	clap.attack("Link");
	trap.attack("Okto");

	return (0);
}
