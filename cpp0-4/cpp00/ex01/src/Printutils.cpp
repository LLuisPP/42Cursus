/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printutils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:38:24 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/17 12:53:40 by lprieto-         ###   ########.fr       */
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
	std::cout << "|                                                  |" << std::endl;
	std::cout << "|     1 - ADD    |   2 - SEARCH   |    3 - EXIT    |" << std::endl;
	std::cout << "|__________________________________________________|\n" << std::endl;
	std::cout << "> Your selection:" << std::endl;
}

void	print_search(void) {
	std::cout << "" << std::endl;
	std::cout << " __________________________________________________ " << std::endl;
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
}

void	print_add(void) {
	std::cout << "" << std::endl;
	std::cout << " __________________________________________________ " << std::endl;
	std::cout << "|                                                  |" << std::endl;
	std::cout << "|                                                  |" << std::endl;
	std::cout << "|     ⠀⠀⠀⠀⣿⣿⣿⣿                                     |" << std::endl;
	std::cout << "|         ⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀ First name: alphabetic       |" << std::endl;
	std::cout << "|     ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀  Last name: alphabetic        |" << std::endl;
	std::cout << "|     ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿    Nickname: alpha-numeric      |" << std::endl;
	std::cout << "|      ⠀⠀⠀⣿⣿⣿⣿⠀⠀⠀⠀⠀   Phone: numeric               |" << std::endl;
	std::cout << "|        ⠀⣿⣿⣿⣿⠀⠀⠀⠀⠀   Dark Secret: alpha-numeric   |" << std::endl;
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
	std::cout << "|  \033[1;91m X\e[X     CLOSING PHONEBOOK, SEE YOU SOON    \033[1;91m X\e[0m    |" << std::endl;
	std::cout << "|__________________________________________________|" << std::endl;
	std::cout << "" << std::endl;
}

void	print_first(void) {
	std::cout << "" << std::endl;
	std::cout << " > FIRST NAME input:" << std::endl;
	std::cout << "" << std::endl;
}

void	print_last(void) {
	std::cout << "" << std::endl;
	std::cout << " > LAST NAME input:" << std::endl;
	std::cout << "" << std::endl;
}

void	print_nickname(void) {
	std::cout << "" << std::endl;
	std::cout << " > NICKNAME input:" << std::endl;
	std::cout << "" << std::endl;
}
void	print_phone(void) {
	std::cout << "" << std::endl;
	std::cout << " > PHONE input:" << std::endl;
	std::cout << "" << std::endl;
}
void	print_darksecret(void) {
	std::cout << "" << std::endl;
	std::cout << " > DARK SECRET input:" << std::endl;
	std::cout << "" << std::endl;
}

void	print_contactsuccess(void) {
	std::cout << "" << std::endl;
	std::cout << "+ + + + + + + + + + + + + + + + + + + + + + + + + +" << std::endl;
	std::cout << "\033[1;92m __________________________________________________ " << std::endl;
	std::cout << "|                                                  |" << std::endl;
	std::cout << "|   + + +    CONTACT SUCCESSFULLY CREATED   + + +  |" << std::endl;
	std::cout << "|__________________________________________________|\e[0m" << std::endl << std::endl;
}

void	print_inputError(void) {
	std::cout << "\033[1;91m X: Invalid input ...\e[0m" << std::endl;
}

void	print_inputClose(void) {
	std::cout << "\033[1;91m X: aborting operation and exiting ...\e[0m" << std::endl;
}

void	print_indexerror(void) {
	std::cout << std::endl << "\033[1;91m X: Invalid or inexistent index, exiting ...\e[0m" << std::endl;
}

void	print_alphabetic(void) {
	std::cout << "" << std::endl;
	std::cout << "\033[1;91m X\e[0m: Only alphabetic abc..ABC.." << std::endl;
	std::cout << "" << std::endl;
}

void	print_numeric(void) {
	std::cout << "" << std::endl;
	std::cout << "\033[1;91m X\e[0m: Only numeric 123.." << std::endl;
	std::cout << "" << std::endl;
}

void	print_alphanumeric(void) {
	std::cout << "" << std::endl;
	std::cout << "\033[1;91m X\e[0m: Only alpha-numeric abc..ABC.. 123.." << std::endl;
	std::cout << "" << std::endl;
}

void	print_menuerror(void) {
	std::cout << "" << std::endl;
	std::cout << std::endl << "\t\033[1;91m X X X - Wrong option, try again - X X X\e[0m" << std::endl;
	std::cout << "" << std::endl;
}

