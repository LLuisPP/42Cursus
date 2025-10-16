/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:56:11 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/16 22:47:41 by lprieto-         ###   ########.fr       */
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
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
			phonebook.makeContact();
		else if (input == "SEARCH")
			print_search();
		else
			std::cout << "Wrong option, try again" << std::endl;
		print_instructions();
	}
	print_shutdown();
	return (0);
}
