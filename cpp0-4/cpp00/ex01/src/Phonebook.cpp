/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:14:24 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/17 01:03:24 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void) : _contactIndex(0), _totalContacs(8) {};
Phonebook::~Phonebook(void) {};


void Phonebook::makeContact(void) {
	Contact	newContact;
	std::string input;
	
	print_add();
	while(true) {
		print_first();
		std::getline(std::cin, input);
		if(std::cin.eof()) { print_inputClose();
			return ;
		}
		else if (newContact.setFirstName(input)) {break ;}
	};
	
	while(true) {
		print_last();
		std::getline(std::cin, input);
		if(std::cin.eof()) { print_inputClose();
			return ;
		}
		else if (newContact.setLastName(input)) {break ;}
	};

	while(true) {
		print_nickname();
		std::getline(std::cin, input);
		if(std::cin.eof()) { print_inputClose();
			return ;
		}
		else if (newContact.setNickname(input)) {break ;}
	};

	while(true) {
		print_phone();
		std::getline(std::cin, input);
		if(std::cin.eof()) { print_inputClose();
			return ;
		}
		else if (newContact.setPhone(input)) {break ;}
	};
	
	while(true) {
		print_darksecret();
		std::getline(std::cin, input);
		if(std::cin.eof()) { print_inputClose();
			return ;
		}
		else if (newContact.setDarkSecret(input)) {break ;}
	};
	
	this->_contact[this->_contactIndex] = newContact;
	this->_contactIndex = (this->_contactIndex + 1) % 8;
	print_contactsuccess();
};

void Phonebook::searchContacts(void) const {
	print_search();
	std::cout << "" << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "_____________________________________" << std::endl;

	for (int i = 0; i < 8; ++i) {
		std::string _firstName = this->_contact[i].getFirstName();
		if(_firstName.empty()) {
			continue;
		}
	}
	
}