/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 22:37:24 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/10 22:37:25 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

// Example functions
template <typename T>
void	printElement(T const &element) {
	std::cout << element << " ";
}

void	increment(int &n) {
	n++;
}

int	main(void) {
	int intArray[] = {1, 2, 3, 4, 5, 9, 6};
	size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original intArray: ";
	::iter(intArray, intLen, printElement<int>);
	std::cout << std::endl;

	::iter(intArray, intLen, increment);

	std::cout << "Incremented intArray: ";
	::iter(intArray, intLen, printElement<int>);
	std::cout << std::endl;

	std::string strArray[] = {"Hello", "world", "from", "42"};
	size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << "String Array: ";
	::iter(strArray, strLen, printElement<std::string>);
	std::cout << std::endl;

	return (0);
}
