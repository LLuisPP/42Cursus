/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:30:58 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/01 11:31:07 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





/*

        Animal               (BASE: con virtual)
     ┌──────────┐
     │ type     │  protected
     │ getType  │  virtual? (suele ser no-virtual)
     │ makeSound│  virtual
     │ ~Animal  │  virtual
     └────▲─────┘
          │ public
   ┌──────┴───────┐
   │              │
┌──┴───┐      ┌───┴───┐
│  Dog │      │  Cat  │   (ambas override de makeSound)
└──────┘      └───────┘

Animal con atributo type y makeSound() virtual; Dog/Cat heredan y sobre-escriben makeSound()
 (perro no maúlla, gato no ladra). El main del subject invoca vía puntero a base y debe oírse 
 el sonido específico (polimorfismo dinámico). Destructor virtual para borrar por Animal* sin leaks.

*/