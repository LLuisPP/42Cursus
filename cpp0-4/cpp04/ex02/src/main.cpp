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

#include "Dog.hpp"
#include "Cat.hpp"

// int	main(void)
// {
// 	int	n = 100;
// 	Animal	*animals[100];
// 	for (int i = 0; i < n / 2; i++)
// 	{
// 		animals[i] = new Dog();
// 		animals[i + n / 2] = new Cat();
// 	}
// 	for (int i = 0; i < n; i ++)
// 		delete animals[i];
// 	std::cout << " - - - - - - END - - - - - - " << std::endl;

// 	Dog	dog, dogCopy;
// 	dog.getBrain()->setIdea("I must eat poop", 12);
// 	dogCopy = dog;

// 	std::cout << "DOG ideas: "  << dog.getBrain()->getIdeas()[12]  << std::endl;
// 	std::cout << "DOG COPY ideas: "  << dogCopy.getBrain()->getIdeas()[12] << std::endl;

// 	return (0);
// }


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

    return 0;
}




/*

        Animal (BASE: virtual makeSound, ~virtual)
           ▲
     ┌─────┴─────┐
     │           │
    Dog         Cat
     │           │
     └─ has → Brain* (100 ideas)  ←─┘   (composición con new/delete)

*/