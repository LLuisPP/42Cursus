/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:46:43 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/17 00:44:23 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

// # include "Phonebook.hpp"
# include <iostream>
# include <string>
# include <cctype>

class Contact {
	
	private:
	std::string _firstName;
	std::string _lastName;
	std::string	_nickname;
	std::string	_phone;
	std::string _darkSecret;


	//VALIDATORS
		bool	validAlpha(const std::string& str);
		bool	validNumber(const std::string& str);
		bool	validAlphaNum(const std::string& str);

	public:
		Contact(void);
		~Contact(void);
		
	
		// SETTERS
		bool 	setFirstName(const std::string& str);
		bool	setLastName(const std::string& str);
		bool	setNickname(const std::string& str);
		bool	setPhone(const std::string& str);
		bool	setDarkSecret(const std::string& str);

		// GETTERS
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getPhone(void) const;
		std::string	getDarkSecret(void) const;

		//FUNCTIONS
		
};

	void	print_initial(void);
	void	print_shutdown(void);
	void	print_instructions(void);
	void	print_search(void);
	void	print_add(void);
	void	print_first(void);
	void	print_last(void);
	void	print_nickname(void);
	void	print_phone(void);
	void	print_darksecret(void);
	void	print_contactsuccess(void);
	void	print_inputError(void);
	void	print_inputClose(void);
	void	print_alphabetic(void);
	void	print_numeric(void);
	void	print_alphanumeric(void);
	
#endif
