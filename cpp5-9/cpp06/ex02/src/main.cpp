/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:53:59 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/10 21:54:01 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	int random = std::rand() % 3;
	if (random == 0) return (new A());
	else if (random == 1) return (new B());
	else return (new C());
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
	else std::cout << "Unknown" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (std::exception& e) {}
	
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (std::exception& e) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (std::exception& e) {}

	std::cout << "Unknown" << std::endl;
}

int main() {
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (int i = 0; i < 10; ++i) {
		Base *ptr = generate();
		std::cout << "Test " << i + 1 << ":\n";
		std::cout << "  Identify via pointer:   ";
		identify(ptr);
		std::cout << "  Identify via reference: ";
		identify(*ptr);
		std::cout << "-----------------------" << std::endl;
		delete ptr;
	}

	return (0);
}
