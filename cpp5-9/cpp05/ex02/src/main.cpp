/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:13:13 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/10 20:13:14 by lprieto-         ###   ########.fr       */
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
    std::srand(std::time(0));
    std::cout << "\n--- Creating Bureaucrats ---" << std::endl;
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);
    Bureaucrat middle("Middle", 50);

    std::cout << "\n--- Validating ShrubberyCreationForm ---" << std::endl;
    // sign 145, exec 137
    ShrubberyCreationForm shrub("garden");
    intern.signForm(shrub); // Fails (150 > 145)
    intern.executeForm(shrub); // Fails (not signed, too low)

    middle.signForm(shrub); // Success
    intern.executeForm(shrub); // Fails (too low)
    middle.executeForm(shrub); // Success (creates garden_shrubbery)

    std::cout << "\n--- Validating RobotomyRequestForm ---" << std::endl;
    // sign 72, exec 45
    RobotomyRequestForm robot("Bender");
    middle.signForm(robot); // Success (50 <= 72)
    middle.executeForm(robot); // Fails (50 > 45)

    boss.executeForm(robot); // Success (executes 50% chance block)
    boss.executeForm(robot); // Trying again for randomness

    std::cout << "\n--- Validating PresidentialPardonForm ---" << std::endl;
    // sign 25, exec 5
    PresidentialPardonForm pardon("Arthur Dent");
    middle.signForm(pardon); // Fails
    boss.signForm(pardon); // Success

    middle.executeForm(pardon); // Fails
    boss.executeForm(pardon); // Success

    std::cout << "\n--- Ending test and destroying objects ---" << std::endl;
    return 0;
}
