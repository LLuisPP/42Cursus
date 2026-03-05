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
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {

	ClapTrap	clap("Okto");
    ScavTrap	trap("Link");   // <- ScavTrap (ex01)
	FragTrap	frag("Zelda");  // <- FragTrap (ex02)

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
	
	// ---- ex02: FragTrap ----
	frag.highFiveGuys();          // FragTrap own method
	frag.attack("Link");           // shows Link inherits: attack
	trap.takeDamage(30);           // FragTrap damage (ATK=30)
	// ----------------------------------


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





/*

CLASES
┌───────────────────────────────────┐
│        ClapTrap                   │  (base)
│  _name, _health, _energy, _attack |
│  attack / takeDamage / beRepaired |
│  ctors / dtor / copy / assign     |
└───────────▲───────▲───────────────┘
            │       │  public inherit
┌───────────┴───┐   └───────────────┐  
│    ScavTrap   │         ┌─────────┴────────────────┐ 
│  (derivate)   │         |  FragTrap                |
│  + guardGate  │         |  (derivate)              | 
│  + attack(OVR)│         |  + highFiveGuys          |
│  HP=100 EN=50 │         |  (uses attack inherited) |
│  ATK=20       │         |  HP=100 EN=100 ATK=30    |
└───────────────┘         └──────────────────────────┘

OBJECTS in main()
clap : ClapTrap("Okto")
trap : ScavTrap("Link")
frag : FragTrap("Zelda")

*/