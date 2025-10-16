/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:46:43 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/15 19:16:13 by lprieto-         ###   ########.fr       */
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
	std::string _first_name;
	// std::string _last_name;
	// std::string	_nickname;
	// std::string	_phone;
	// std::string _dark_secret;


	//VALIDATORS
		bool	validAlpha(const std::string& str);
		// bool	validNumber(std::string const &str) const;

		std::string _format(std::string str) const;

	public:
		Contact(void);
		~Contact(void);
		
	
		// SETTERS
		void 	setFirstName(const std::string& str) {
			this->_first_name = str;
		};
		// bool		setLastName(std::string las_name);
		// bool		setNickname(std::string nickname);
		// bool		setPhone(std::string phone);
		// bool		setDarkSecret(std::string dark_secret);

		// GETTERS
		std::string	getFirstName(void) const;
		// std::string	getLastName(void) const;
		// std::string	getNickname(void) const;
		// std::string	getPhone(void);
		// std::string	getDarkSecret(void);

		//FUNCTIONS
		
};

	void		print_initial(void);
	void		print_shutdown(void);
	void		print_instructions(void);
	void		print_search(void);
	void		print_add(void);
	void		print_first(void);
	void		inputError();

#endif
