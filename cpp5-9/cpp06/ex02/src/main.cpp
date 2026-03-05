/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:38:04 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/22 17:51:01 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv) {

	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	if (argc != 1) {
		std::cout << "No arguments required !" << std::endl;
		return (1);
	}
	(void)argv;

	std::cout << "String:\t\t" << &string << std::endl;

	std::cout << "StringPTR:\t" << stringPTR << std::endl;

	std::cout << "StringREF:\t" << &stringREF << std::endl << std::endl;
	std::cout << "(pointer var):\t" << (const void*)&stringPTR << std::endl;
	std::cout << std::endl;

	std::cout << "String:\t\t" << string << std::endl;
	std::cout << "StringPTR:\t" << *stringPTR << std::endl;
	std::cout << "StringREF:\t" << stringREF << std::endl;
	return (0);
}
