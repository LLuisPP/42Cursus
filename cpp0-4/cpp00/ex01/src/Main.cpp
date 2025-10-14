/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:56:11 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/14 20:02:01 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"

void	print_initial(void) {
	std::cout << "|>------------------------------<|" << std::endl;
	std::cout << "|> Welcome to my awesome agenda <|" << std::endl;
	std::cout << "|>------------------------------<|" << std::endl;

	std::cout << "                                  " << std::endl;
	std::cout << ">    Please choose an option     <" << std::endl;
	std::cout << "                                  " << std::endl;
	std::cout << ">\tADD" << std::endl;
	std::cout << ">\tSEARCH" << std::endl;
	std::cout << ">\tEXIT" << std::endl;
}

void	print_instructions(void) {
	std::cout << "" << std::endl;
	std::cout << "|>------------------------------<|" << std::endl;
	std::cout << "|>   Please choose an option:   <|" << std::endl;
	std::cout << "|>------------------------------<|" << std::endl << std::endl;
	std::cout << "\tADD" << std::endl;
	std::cout << "\tSEARCH" << std::endl;
	std::cout << "\tEXIT" << std::endl;
}



Contact	make_contact(void)
{
}


int	main(void) {

	Phonebook	phonebook;
	std::string	input;

	print_initial();
	
	while (std::getline(std::cin, input)) {
		if (input == "EXIT")
			return (0);
		else if (input == "ADD")
			std::cout << "ADD is working" << std::endl;
		else if (input == "SEARCH")
			std::cout << "SEARCH is working" << std::endl;
		else
			std::cout << "Wrong option, try again" << std::endl;
		print_instructions();
	}
	return (0);
}
