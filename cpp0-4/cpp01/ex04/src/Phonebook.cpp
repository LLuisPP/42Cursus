/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:14:24 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/17 19:14:52 by lprieto-         ###   ########.fr       */
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
	std::cout << "|          |             |            |            |" << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << "   " << std::setw(10) << "First Name" << "|";
	std::cout << "  " << std::setw(10) << "Last Name" << "|";
	std::cout << "  " << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "|__________|_____________|____________|____________|" << std::endl;

	for (int i = 0; i < 8; ++i) {
		std::string _firstName = this->_contact[i].getFirstName();
		if(_firstName.empty()) {
			continue;
		}
		std::cout << "|" << std::setw(10) << i;
		if (this->_contact[i].getFirstName().length() > 9)
			std::cout << "|   " << std::setw(10) << this->_contact[i].getFirstName().substr(0, 9) + ".";
		else
			std::cout << "|   " << std::setw(10) << this->_contact[i].getFirstName();
		if (this->_contact[i].getLastName().length() > 9)
			std::cout << "|  " << std::setw(10) << this->_contact[i].getLastName().substr(0, 9) + ".";
		else
			std::cout << "|  " << std::setw(10) << this->_contact[i].getLastName();
		if (this->_contact[i].getNickname().length() > 9)
			std::cout << "|  " << std::setw(10) << this->_contact[i].getNickname().substr(0, 9) + "." << "|" << std::endl;
		else
			std::cout << "|  " << std::setw(10) << this->_contact[i].getNickname() << "|" << std::endl;
	}
			std::cout << "|__________|_____________|____________|____________|" << std::endl;
			
	std::string input;
	int			index = -1;

	std::cout << std::endl << "Select an index to see details (0 - 7):" << std::endl;
	std::getline(std::cin, input);
	if (input.length() >= 2) {
		print_inputClose();
		return ;
	}
	if (std::isdigit(input[0])) {
		index = input[0] - '0';
	}
	else {
		print_inputClose();
		return ;
	}
	
	if (index >= 0 && index <= 7) {
		if (this->_contact[index].getFirstName().empty()) {
			std::cout << " \033[1;91m  X: Index contains no information to show \e[0m" << std::endl;
			return ;
		}
		std::cout << "Index contains no information to show" << std::endl;
		if (std::cin.eof() || !input[0] || input[1]) {
			print_inputError();
			return ;
		}
	}
	else {
		print_indexerror();
		return ;
	}

	std::cout << "\033[1;92m __________________________________________________ " << std::endl;
	std::cout << "| " << std::endl;
	std::cout << "| " << this->_contact[index].getFirstName() << std::endl;
	std::cout << "| " << this->_contact[index].getLastName() << std::endl;
	std::cout << "| " << this->_contact[index].getNickname() << std::endl;
	std::cout << "| " << this->_contact[index].getPhone() << std::endl;
	std::cout << "| " << this->_contact[index].getDarkSecret() << std::endl;
	std::cout << "|___________________________________________________\e[0m" << std::endl;
}
