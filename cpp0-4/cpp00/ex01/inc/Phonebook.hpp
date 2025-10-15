/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:09:31 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/15 20:29:08 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>
# include <iostream>
# include <cctype>

class Phonebook {
	private:
		Contact	_contact[8];
		int		_contactIndex;
		int		_totalContacs;
		
	public:
		Phonebook(void);
		~Phonebook(void);
		
		Contact makeContact(void);
		
};

#endif
