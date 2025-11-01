/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:51:56 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/01 11:51:58 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*

     AAnimal (BASE ABSTRACTA)
   ┌────────────────────────┐
   │ type (protected)       │
   │ virtual ~AAnimal()     │
   │ virtual getType()      │
   │ =0 makeSound()         │  ← pura (base NO instanciable)
   └──────────▲─────────────┘
              │ public
        ┌─────┴────┐
        │          │
       Dog        Cat        (implementan makeSound())


*/