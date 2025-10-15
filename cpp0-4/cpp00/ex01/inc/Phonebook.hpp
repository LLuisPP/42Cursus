/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:09:31 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/15 10:01:49 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include "Contact.hpp"

# define ARRAY_SIZE 8;

class Phonebook {
	private:
		Contact	_contact[8];
		size_t	last_updated_contact;
	public:
		Phonebook(void);
		
		Contact	get_contact(size_t index);
		void	add__contact(Contact contact);

		~Phonebook(void);
};

#endif
