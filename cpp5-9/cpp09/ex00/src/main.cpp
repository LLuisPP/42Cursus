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


   std::cout << "\n - - - [Polymorphism] - - -\n";

	animal->makeSound();
	dog->makeSound();
	cat->makeSound();

   std::cout << "\n x x x [Wrong hierarchy] x x x\n";
	wrongAnimal->makeSound();
	wrongCat->makeSound();

   std::cout << "\n x x x [Destructors] x x x\n";
	delete dog;
	delete cat;
	delete wrongAnimal;
	delete wrongCat;
	delete animal;
	return (0);
}

/*

        Animal               (BASE: with virtual)
     ┌──────────┐
     │ type     │  protected
     │ getType  │  usually non-virtual
     │ makeSound│  virtual
     │ ~Animal  │  virtual
     └────▲─────┘
          │ public
   ┌──────┴───────┐
   │              │
┌──┴───┐      ┌───┴───┐
│  Dog │      │  Cat  │   (both override makeSound)
└──────┘      └───────┘


Animal has a type attribute and a virtual makeSound() function;
Dog and Cat inherit from it and override makeSound()
(a dog doesn’t meow, and a cat doesn’t bark).

The subject’s main calls makeSound() through a base pointer,
and the specific sound of each derived class must be heard
(dynamic polymorphism).

A virtual destructor is used so objects can be deleted through an Animal*
without causing memory leaks.

*/