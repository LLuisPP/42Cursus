/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:40:05 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/15 20:09:58 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// CONSTRUCTOR/DESTRUCTOR

Contact::Contact(void) {}
Contact::~Contact(void) {}


// PRIVATE FUNCTS
bool	Contact::validAlpha(std::string const &str) {
	for(int i = 0; i < str.length(); ++i) {
		if(!std::isalpha(str[i]) && str[i] != ' ' && str[i] != '-')
			return (false);
	}
	return (true);
}


// bool	Contact::validNumber(std::string const &str) {
// 	for(int i = 0; i < str.length(); ++i) {
// 		if(!std::isalpha(str[i]) && str[i] != ' ' && str[i] != '-')
// 		{
// 			std::cout << "whatafac" << std::endl;
// 			return (false);
// 		}
// 	}
// 	return (true);
// }



// SETTERS
// bool	Contact::set_first_name(std::string _frist_name) {
// 	if (str.empty()) {
// 		std::cout << "Error: The field is empty, fill the blank, please" << std::endl;
// 		return (false);
// 	} else if (!this->validAlpha(str)) {
// 		std::cout << "! Only alphabetic abc..ABC.." << std::endl;
// 		return (false);
// 	}
// 	this->_first_name;
// 	return (true);
// }

// bool	Contact::set_last_name(std::string _last_name) {
// 	if (str.empty()) {
// 		std::cout << "Error: The field is empty, fill the blank, please" << std::endl;
// 		return (false);
// 	} else if (!this->_isAlpha(str)) {
// 		std::cout << "! Pnly alphabetic abc..ABC.." << std::endl;
// 		return (false);
// 	}
// 	this->_last_name;
// 	return (true);
// }

// bool	Contact::set_nickname(std::string _nickname) {
// 	if (str.empty()) {
// 		std::cout << "Error: The field is empty, fill the blank, please" << std::endl;
// 		return (false);
// 	} else if (!this->_isAlpha(str)) {
// 		std::cout << "! Only alpha-numeric abc..ABC..123.." << std::endl;
// 		return (false);
// 	}
// 	this->_nickname;
// 	return (true);
// }

// bool	Contact::set_phone(std::string _phone) {
// 	if (str.empty()) {
// 		std::cout << "Error: The field is empty, fill the blank, please" << std::endl;
// 		return (false);
// 	} else if (!this->_isAlpha(str)) {
// 		std::cout << "! Only numeric 123.." << std::endl;
// 		return (false);
// 	}
// 	this->_phone;
// 	return (true);
// }

// bool	Contact::set_dark_secret(std::string _dark_secret) {
// 	if (str.empty()) {
// 		std::cout << "Error: The field is empty, fill the blank, please" << std::endl;
// 		return (false);
// 	}
// 	this->_dark_secret;
// 	return (true);
// }

// Getters

// std::string Contact::get_first_name(void) {
// 	return (this->_first_name);
// };

// std::string Contact::get_last_name(void) {
// 	return (this->_last_name);
// };

// std::string Contact::get_nickname(void) {
// 	return (this->_nickname);
// };

// std::string Contact::get_phone(void) {
// 	return (this->_phone);
// };

// std::string Contact::get_dark_secret(void) {
// 	return (this->_dark_secret);
// };



// bool Contact::isEmpty(void) {
// 	return (this->_first_name.empty() || this._last_name.empty() || this._nickname.empty()
// 	|| this->_phone.empty() || this->_dark_secret.empty());
// }
