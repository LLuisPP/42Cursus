/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:14:24 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/15 21:55:49 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void) {};
Phonebook::~Phonebook(void) {};


Contact Phonebook::makeContact(void) {
	Contact	newContact;
	std::string input;
	
	while(true) {
		print_first();
		std::getline(std::cin, input);

		if (input.empty()) {
			inputError();
			break ;
		}
		else if(std::cin.eof()) {
			std::cout << "Input closed" << std::endl;
			return (Contact());
		}
		if (!input.empty()) {
			// newContact.setFirstName(input); //segfault
			this->_contact[this->_contactIndex] = newContact; // segfault
			std::cout << "empty antes" << std::endl;
			this->_contactIndex = (this->_contactIndex + 1) % 8;
			std::cout << "empty despues" << std::endl;
			std::cout << "Contact added successfully" << std::endl;
			break ;
		}
	};
	return (newContact);
}
