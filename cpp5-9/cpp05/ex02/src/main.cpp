/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:13:13 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/11 19:40:26 by lprieto-         ###   ########.fr       */
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
    std::srand(std::time(0)); // For 50% of Robotomy success

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
        intern.signForm(shrub); // Should fail

        std::cout << "> Action: Middle (50) signs and executes" << std::endl;
        middle.signForm(shrub); // Should succeed
        middle.executeForm(shrub); // Should succeed and create file
    } catch (std::exception &e) {
        std::cout << RED << "Unexpected Exception: " << e.what() << RESET << std::endl;
    }

    // --- TEST: RobotomyRequestForm ---
    std::cout << YELLOW << "\n--- TEST 2: Robotomy (Sign 72, Exec 45) ---" << RESET << std::endl;
    
    try {
        RobotomyRequestForm robot("Bender");
        std::cout << robot << std::endl;

        middle.signForm(robot); // Success (50 <= 72)
        
        std::cout << "> Action: Middle (50) tries to execute (needs 45)" << std::endl;
        middle.executeForm(robot); // Should fail

        std::cout << "> Action: Boss (1) executes (50% chance)" << std::endl;
        boss.executeForm(robot); // Success
        boss.executeForm(robot); // Another try for randomness
    } catch (std::exception &e) {
        std::cout << RED << "Caught Exception: " << e.what() << RESET << std::endl;
    }

    // --- TEST: PresidentialPardonForm ---
    std::cout << YELLOW << "\n--- TEST 3: Presidential Pardon (Sign 25, Exec 5) ---" << RESET << std::endl;
    
    try {
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << pardon << std::endl;

        std::cout << "> Action: Middle (50) tries to sign" << std::endl;
        middle.signForm(pardon); // Should fail

        std::cout << "> Action: Boss (1) signs and executes" << std::endl;
        boss.signForm(pardon); // Success
        boss.executeForm(pardon); // Success
    } catch (std::exception &e) {
        std::cout << RED << "Caught Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << MAGENTA << "\n--- All tests completed. Cleaning up ---" << RESET << std::endl;
    return 0;
}

/*
             AForm (Abstract Class)                      Bureaucrat
      ┌──────────────────────────────────┐        ┌──────────────────────────┐
      │ - _name (const)                  │        │ - _grade [1..150]        │
      │ - _isSigned (bool)               │        ├──────────────────────────┤
      │ - _gradeToSign (const)           │        │ + signForm(AForm &)      │
      │ - _gradeToExecute (const)        │        │ + executeForm(AForm &)   │
      ├──────────────────────────────────┤        └────────────┬─────────────┘
      │ + beSigned(Bureaucrat &)         │                     │
      │ + execute(Bureaucrat const &)    │<────────────────────┘
      │ virtual executeAction() = 0      │      Calls AForm::execute(*this)
      └───────────────┬──────────────────┘
                      │
      ┌───────────────┼──────────────────────────────┐
      │               │                              │
┌─────┴─────┐   ┌─────┴─────────────┐   ┌────────────┴─────────────┐
│ Shrubbery │   │ RobotomyRequest   │   │ PresidentialPardon       │
│ Creation  │   │ Form              │   │ Form                     │
├───────────┤   ├───────────────────┤   ├──────────────────────────┤
│ Sign: 145 │   │ Sign: 72          │   │ Sign: 25                 │
│ Exec: 137 │   │ Exec: 45          │   │ Exec: 5                  │
└───────────┘   └───────────────────┘   └──────────────────────────┘

- AForm: Base attributes remain private, not protected.
- execute(): Base function checks if the form is signed AND if the 
  executor's grade is high enough. If not, throws exception.
- executeAction() (or similar): Pure virtual function implemented in 
  concrete classes to perform the specific form requirement.
- ShrubberyCreationForm: Creates <target>_shrubbery with ASCII trees.
- RobotomyRequestForm: 50% success drilling noise/robotomy.
- PresidentialPardonForm: Informs target is pardoned by Zaphod Beeblebrox.
- Bureaucrat::executeForm(): Attempts execution and prints:
    Success: "<bureaucrat> executed <form>".
    Failure: Prints an explicit error message.
*/