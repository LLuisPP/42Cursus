/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:56:11 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/17 08:53:54 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"

int	main(void) {

	Phonebook	phonebook;
	std::string	input;

	print_initial();
	print_instructions();
	while (std::getline(std::cin, input)) {
		if (input == "ADD" || input == "add" || input == "1")
		phonebook.makeContact();
		else if (input == "SEARCH" || input == "search" || input == "2")
		phonebook.searchContacts();
		else if (input == "EXIT" || input == "exit" || input == "3")
		break ;
		else
			print_menuerror();
		print_instructions();
	}
	print_shutdown();
	return (0);
}
