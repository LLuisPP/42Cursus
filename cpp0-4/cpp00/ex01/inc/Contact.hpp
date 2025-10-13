/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:46:43 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/13 18:07:41 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {
	private:
		std::string first_name
		std::string last_name
		std::string	nickname
		std::string	phone
		str::string dark_secret

	public:
		Contact(void);
		void	set_contact(std::string first_name, std::string last_name,
				std::string nickname, std::string phone, std::dark_secret);
		std::string get_content(int option);
		~Contact(void);
};

#endif
