/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:46:43 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/14 18:42:36 by lprieto-         ###   ########.fr       */
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

	public:
		Contact(void);

		void set_first_name(std::string first_name);
		void set_last_name(std::string las_name);
		void set_nickname(std::string nickname);
		void set_phone(std::string phone);
		void set_dark_secret(std::string dark_secret);

		std::string get_first_name(void);
		std::string get_last_name(void);
		std::string get_nickname(void);
		std::string get_phone(void);
		std::string get_dark_secret(void);

		~Contact(void);
};

#endif
