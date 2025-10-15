/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:46:43 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/15 11:47:13 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {
	private:
		std::string _first_name;
		std::string _last_name;
		std::string	_nickname;
		std::string	_phone;
		std::string _dark_secret;

		bool	isAlpha(std::string const &str);
		bool	isNumber(std::string const &str);

	public:
		Contact(void);
		~Contact(void);

		// SETTERS
		bool		set_first_name(std::string first_name);
		bool		set_last_name(std::string las_name);
		bool		set_nickname(std::string nickname);
		bool		set_phone(std::string phone);
		bool		set_dark_secret(std::string dark_secret);

		// GETTERS
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nickname(void);
		std::string	get_phone(void);
		std::string	get_dark_secret(void);
};

	void		print_initial(void);
	void		print_shutdown(void);
	void		print_instructions(void);
	void		print_search(void);
	void		print_add(void);

#endif
