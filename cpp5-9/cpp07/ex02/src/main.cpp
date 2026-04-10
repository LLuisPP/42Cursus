/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 22:37:38 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/10 22:37:39 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**) {
	Array<int>	numbers(MAX_VAL);
	int*		mirror = new int[MAX_VAL];

	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	std::cout << "--- Primeros 5 valores generados aleatoriamente ---" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << "numbers[" << i << "]:\t" << numbers[i] << std::endl;
	}
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << "Forzando salidas de limites para testear la Exception:" << std::endl;

	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << "didn't save the same value!!" << std::endl;
			return (1);
		}
	}

	try {
		std::cout << "-> Probando a modificar el indice: -2" << std::endl;
		numbers[-2] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << "   Error devuelto: " << e.what() << '\n';
	}

	try {
		std::cout << "-> Probando a modificar el indice: MAX_VAL (" << MAX_VAL << ")" << std::endl;
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << "   Error devuelto: " << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
	}

	delete[] mirror;
	return (0);
}
