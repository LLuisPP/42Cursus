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





/*

[Clase base]
┌──────────────────────────┐
│        ClapTrap          │
│ ───────────────────────  │
│  - _name                 │
│  - _health (=10)         │
│  - _energy (=10)         │
│  - _attack (=0)          │
│ ───────────────────────  │
│  + attack(target)        │
│  + takeDamage(amount)    │
│  + beRepaired(amount)    │
│  + ctor/dtor/copy/assign │
└───────────▲──────────────┘
            │  herencia pública
[Clase derivada]
┌───────────┴──────────────┐
│         ScavTrap         │
│ ───────────────────────  │
│  (hereda todo lo de      │
│   ClapTrap y añade:)     │
│  - _guard (estado)       │
│  (ajusta stats iniciales)│
│   _health=100            │
│   _energy=50             │
│   _attack=20             │
│ ───────────────────────  │
│  + attack(target)  [OVR] │
│  + guardGate()           │
│  + ctors/dtor propios    │
└──────────────────────────┘

*/