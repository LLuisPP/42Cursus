/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:13:13 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/11 19:33:06 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0)); // Para el 50% de éxito de Robotomy [cite: 199]

    std::cout << MAGENTA << "--- STEP 1: Creating Bureaucrats ---" << RESET << std::endl;
    Bureaucrat boss("Boss", 1);
    Bureaucrat middle("Middle", 50);
    Bureaucrat intern("Intern", 150);
    std::cout << boss << "\n" << middle << "\n" << intern << std::endl;

    // --- TEST: ShrubberyCreationForm ---
    std::cout << YELLOW << "\n--- TEST 1: Shrubbery (Sign 145, Exec 137) ---" << RESET << std::endl;
    try {
        ShrubberyCreationForm shrub("garden");
        std::cout << shrub << std::endl;

        std::cout << "> Action: Intern (150) tries to sign" << std::endl;
        intern.signForm(shrub); // Should fail [cite: 176, 196]

        std::cout << "> Action: Middle (50) signs and executes" << std::endl;
        middle.signForm(shrub); // Should succeed [cite: 175, 196]
        middle.executeForm(shrub); // Should succeed and create file [cite: 197, 208]
    } catch (std::exception &e) {
        std::cout << RED << "Unexpected Exception: " << e.what() << RESET << std::endl;
    }

    // --- TEST: RobotomyRequestForm ---
    std::cout << YELLOW << "\n--- TEST 2: Robotomy (Sign 72, Exec 45) ---" << RESET << std::endl;
    try {
        RobotomyRequestForm robot("Bender");
        std::cout << robot << std::endl;

        middle.signForm(robot); // Success (50 <= 72) [cite: 198]
        
        std::cout << "> Action: Middle (50) tries to execute (needs 45)" << std::endl;
        middle.executeForm(robot); // Should fail [cite: 209]

        std::cout << "> Action: Boss (1) executes (50% chance)" << std::endl;
        boss.executeForm(robot); // Success [cite: 199]
        boss.executeForm(robot); // Another try for randomness [cite: 199]
    } catch (std::exception &e) {
        std::cout << RED << "Caught Exception: " << e.what() << RESET << std::endl;
    }

    // --- TEST: PresidentialPardonForm ---
    std::cout << YELLOW << "\n--- TEST 3: Presidential Pardon (Sign 25, Exec 5) ---" << RESET << std::endl;
    try {
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << pardon << std::endl;

        std::cout << "> Action: Middle (50) tries to sign" << std::endl;
        middle.signForm(pardon); // Should fail [cite: 201]

        std::cout << "> Action: Boss (1) signs and executes" << std::endl;
        boss.signForm(pardon); // Success [cite: 201]
        boss.executeForm(pardon); // Success [cite: 201, 202]
    } catch (std::exception &e) {
        std::cout << RED << "Caught Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << MAGENTA << "\n--- All tests completed. Cleaning up ---" << RESET << std::endl;
    return 0;
}