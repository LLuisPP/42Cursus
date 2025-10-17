/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:40:05 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/17 12:40:38 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// CONSTRUCTOR/DESTRUCTOR

Contact::Contact(void) {
	this->_firstName = "";
	this->_lastName = "";
	this->_nickname = "";
	this->_phone = "";
	this->_darkSecret = "";	
};

Contact::~Contact(void) {};


// PRIVATE FUNCTS
bool	Contact::validAlpha(std::string const &str) {
	for(int i = 0; i < str.length(); ++i) {
		if(!std::isalpha(str[i]) && str[i] != ' ' && str[i] != '-')
		return (false);
	}
	return (true);
}

bool	Contact::validNumber(std::string const &str) {
	for(int i = 0; i < str.length(); ++i) {
		if(!std::isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
		return (false);
	}
	return (true);
}

bool	Contact::validAlphaNum(std::string const &str) {
	for(int i = 0; i < str.length(); ++i) {
		if(!std::isalnum(str[i]) && str[i] != ' ' && str[i] != '-')
		return (false);
	}
	return (true);
}

// GETTERS

std::string Contact::getFirstName(void) const {
	return (this->_firstName);
};
std::string Contact::getLastName(void) const {
	return (this->_lastName);
};
std::string Contact::getNickname(void) const {
	return (this->_nickname);
};
std::string Contact::getPhone(void) const {
	return (this->_phone);
};
std::string Contact::getDarkSecret(void) const {
	return (this->_darkSecret);
};


// SETTERS
bool	Contact::setFirstName(const std::string& str) {
	if (str.empty()) {
		std::cout << "Empty fields are NOT allowed" << std::endl;
		return (false);
	}
	else if (!this->validAlpha(str)) {
		print_alphabetic();
		return (false);
	}
	this->_firstName = str;
	return (true);
}

bool	Contact::setLastName(const std::string& str) {
	if (str.empty()) {
		std::cout << "Empty fields are NOT allowed" << std::endl;
		return (false);
	}
	else if (!this->validAlpha(str)) {
		print_alphabetic();
		return (false);
	}
	this->_lastName = str;
	return (true);
}

bool	Contact::setNickname(const std::string& str) {
	if (str.empty()) {
		std::cout << "Empty fields are NOT allowed" << std::endl;
		return (false);
	}
	else if (!this->validAlphaNum(str)) {
		print_alphanumeric();
		return (false);
	}
	this->_nickname = str;
	return (true);
}

bool	Contact::setPhone(const std::string& str) {
	if (str.empty()) {
		std::cout << "Empty fields are NOT allowed" << std::endl;
		return (false);
	}
	else if (!this->validNumber(str)) {
		print_numeric();
		return (false);
	}
	this->_phone = str;
	return (true);
}

bool	Contact::setDarkSecret(const std::string& str) {
	if (str.empty()) {
		std::cout << "Empty fields are NOT allowed" << std::endl;
		return (false);
	}
	else if (!this->validAlphaNum(str)) {
		print_alphanumeric();
		return (false);
	}
	this->_darkSecret = str;
	return (true);
}



// bool Contact::isEmpty(void) {
// 	return (this->_first_name.empty() || this._last_name.empty() || this._nickname.empty()
// 	|| this->_phone.empty() || this->_dark_secret.empty());
// }
