/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printutils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:38:24 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/15 21:59:39 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"

void	print_initial(void) {
	std::cout << "" << std::endl;
	std::cout << " __________________________________________________ " << std::endl;
	std::cout << "|                                                  |" << std::endl;
	std::cout << "|   +     WELCOME TO MY AWESOME PHONEBOOK      +   |" << std::endl;
	std::cout << "|__________________________________________________|" << std::endl;
	std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||";
}

void	print_instructions(void) {
	std::cout << "" << std::endl;
	std::cout << " __________________________________________________" << std::endl;
	std::cout << "|                                                  |" << std::endl;
	std::cout << "|             PLEASE CHOOSE AN OPTION              |" << std::endl;
	std::cout << "|__________________________________________________|" << std::endl;
	std::cout << " __________________________________________________ " << std::endl;
	std::cout << "|                                                  |" << std::endl;
	std::cout << "|       ADD      |      SEARCH       |    EXIT     |" << std::endl;
	std::cout << "|__________________________________________________|\n" << std::endl;
	std::cout << "> Your selection:" << std::endl;
}

void	print_search(void) {
	std::cout << "" << std::endl;
	std::cout << " __________________________________________________ " << std::endl;
	std::cout << "|                                                  |" << std::endl;
	std::cout << "|                                                  |" << std::endl;
	std::cout << "|                      ⠀⢀⣰⣶⣶⣿⣿⣿⣿⣿⣶⣶⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀    |" << std::endl;
	std::cout << "|                    ⠀⢀⣴⣿⡿⠟⠋⠉⠉⠉⠉⠉⠙⠻⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀    |" << std::endl;
	std::cout << "|     CONTACT       ⢀⣰⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣆⠀⠀⠀        |" << std::endl;
	std::cout << "|                   ⢸⣿⡿⠁⠀⠀        ⠀⠀⠀⠈⣿⣿⡆⠀⠀        |" << std::endl;
	std::cout << "|     RESULT        ⣿⣿⡇⠀⠀⠀⠀⠀    ⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀⠀       |" << std::endl;
	std::cout << "|                   ⣿⣿⡇⠀⠀⠀⠀       ⠀⠀⠀⠀⢸⣿⣿⠀⠀⠀       |" << std::endl;
	std::cout << "|     LIST          ⢻⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⡏⠀⠀⠀       |" << std::endl;
	std::cout << "|                   ⠸⢿⣿⣦⠀⠀⠀⠀    ⠀⠀⠀⠀⢀⣼⣿⡿⠁⠀⠀⠀       |" << std::endl;
	std::cout << "|                   ⠀⠈⠻⣿⣷⣤⡀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣾⣿⣿⡁⠀⠀⠀⠀       |" << std::endl;
	std::cout << "|                      ⠈⠻⢿⣿⣿⣶⣶⣶⣶⣶⣿⣿⡿⠟⠻⣿⣿⣦⣀⣀⠀⠀⠀     |" << std::endl;
	std::cout << "|                        ⠀⠈⠉⠛⠛⠛⠛⠋⠉⠁⠀⠀⠀⠈⣻⣿⣿⣿⣷⣄⠀⠀    |" << std::endl;
	std::cout << "|                            ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⡷     |" << std::endl;
	std::cout << "|                                 ⠀⠀⠀⠀⠀⠀⠀⠙⢿⡿⠋      |" << std::endl;
	std::cout << "|__________________________________________________|" << std::endl;
	std::cout << "|                                                  |" << std::endl;
	std::cout << "|             SELECT YOUT CONTACT INDEX            |" << std::endl;
	std::cout << "|__________________________________________________|" << std::endl;
	std::cout << "|            |            |            |           |" << std::endl;
	std::cout << "|       INDEX|  FIRST NAME|   LAST NAME|   NICKNAME|" << std::endl;
	std::cout << "|____________|____________|____________|___________|" << std::endl;
}

void	print_add(void) {
	std::cout << "" << std::endl;
	std::cout << " __________________________________________________ " << std::endl;
	std::cout << "|                                                  |" << std::endl;
	std::cout << "|                                                  |" << std::endl;
	std::cout << "|     ⠀⠀⠀⠀⣿⣿⣿⣿                                     |" << std::endl;
	std::cout << "|         ⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀                              |" << std::endl;
	std::cout << "|     ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀   First n: alphabetic        |" << std::endl;
	std::cout << "|     ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿      Last  n: alphabetic        |" << std::endl;
	std::cout << "|      ⠀⠀⠀⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀   nick   :lpha-numeric       |" << std::endl;
	std::cout << "|        ⠀⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀   phone  : numbers           |" << std::endl;
	std::cout << "|                                                  |" << std::endl;
	std::cout << "|__________________________________________________|" << std::endl;
	std::cout << "|                                                  |" << std::endl;
	std::cout << "|           ALL THE FIELDS ARE MANDAROTY           |" << std::endl;
	std::cout << "|__________________________________________________|" << std::endl;
}


void	print_shutdown(void) {
	std::cout << "" << std::endl;
	std::cout << " __________________________________________________" << std::endl;
	std::cout << "|                                                  |" << std::endl;
	std::cout << "|   X     CLOSING PHONEBOOK, SEE YOU SOON     X    |" << std::endl;
	std::cout << "|__________________________________________________|" << std::endl;
	std::cout << "" << std::endl;
}

void	print_first(void) {
	std::cout << "" << std::endl;
	std::cout << "<  INSERT FIRST NAME >" << std::endl;
	std::cout << "" << std::endl;
}

void	inputError(void) {
	std::cout << "Error: Invalid input." << std::endl;
}
