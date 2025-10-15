/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:14:24 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/15 19:30:08 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void) {}
Phonebook::~Phonebook(void) {}

Contact Phonebook::makeContact(void) {
	Contact	newContact;
	std::string input;
	
	print_add();
	while(true) {
		std::cout << "whatafac" << std::endl;

		print_first();
		std::cout << "whatafac2" << std::endl;

		std::getline(std::cin, input);

		if(std::cin.eof())
			std::cout << "whatafac4" << std::endl;
			break ;

		if (!input.empty()) {
			newContact.setFirstName(input);
			break ;
		}
	};
	inputError();
	
	// this->_contact[this->_contactIndex] = newContact;
	// this->_contactIndex = (this->_contactIndex + 1) % 8;
	
	std::cout << "Contact added successfully" << std::endl;
}
