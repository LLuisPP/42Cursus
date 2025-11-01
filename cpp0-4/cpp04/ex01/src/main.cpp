/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:39:10 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/01 11:39:13 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    // --- Polimorphism and destruction by base ---
    const int N = 8;
    Animal* animals[N];

    for (int i = 0; i < N / 2; ++i)
        animals[i] = new Dog();
    for (int i = N / 2; i < N; ++i)
        animals[i] = new Cat();

    for (int i = 0; i < N; ++i)
        delete animals[i];

    std::cout << " - - - - - - END - - - - - - " << std::endl;

    // --- Deep copy: operator= and copy-ctor ---
    Dog original;
    Dog copia;

    // Diagnostics: pointers of Brain (they must be different)
    std::cout << "[ptr] original.brain =" << original.getBrain() << std::endl;
    std::cout << "[ptr] copia.brain    =" << copia.getBrain()    << std::endl;

    // 1) Idea only the original
    original.getBrain()->setIdea("I must eat poop", 82);

    // 2) Copying (operator= with deep copy)
    copia = original;

    // 3) Changing the ORIGINAL after copying
    original.getBrain()->setIdea("CHANGED after copy", 82);

    // 4) Comprobation: this must be diff if there is deep copy
    std::cout << "ORIGINAL idea[82]: " << original.getBrain()->getIdeas()[82] << std::endl;
    std::cout << "COPIA    idea[82]: " << copia.getBrain()->getIdeas()[82]    << std::endl;

    // 5) (Optional) copy-ctor
    Dog clon(original);
    std::cout << "[ptr] clon.brain     =" << clon.getBrain() << std::endl;

    // Changing the original again; clon mustn't change
    original.getBrain()->setIdea("CHANGED again", 82);
    std::cout << "CLON     idea[82]: " << clon.getBrain()->getIdeas()[82]     << std::endl;

    return (0);
}

/*

  CPP04 / ex01 — Composition + Deep Copy

            Animal (BASE: virtual makeSound, virtual destructor)
                   ▲
            ┌──────┴──────┐
            │             │
           Dog           Cat
     (owns Brain*)  (owns Brain*)
            │             │
      ┌─────▼─────┐ ┌─────▼─────┐
      │  Brain    │ │  Brain    │
      │ 100 ideas │ │ 100 ideas │
      └───────────┘ └───────────┘

Key points:
- Each Dog and each Cat allocates its OWN Brain with new Brain() in the constructor.
- Destructor deletes Brain (no leaks).
- Copy constructor and operator= perform a DEEP COPY (clone Brain content, do not share pointers).
- Polymorphism: call makeSound() via Animal* and get the derived behavior.
- Deleting via Animal* correctly calls derived destructors thanks to Animal’s virtual destructor.

*/
