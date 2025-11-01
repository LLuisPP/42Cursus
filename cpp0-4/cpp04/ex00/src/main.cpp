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

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	Animal	*animal = new Animal();
	Animal	*dog = new Dog();
	Animal	*cat = new Cat();
	WrongAnimal	*wrongAnimal = new WrongAnimal();
	WrongAnimal	*wrongCat = new WrongCat();

	animal->makeSound();
	dog->makeSound();
	cat->makeSound();
	wrongAnimal->makeSound();
	wrongCat->makeSound();

	delete animal;
	delete dog;
	delete cat;
	delete wrongAnimal;
	delete wrongCat;
	return (0);
}

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