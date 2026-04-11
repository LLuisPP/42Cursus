/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:14:12 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/11 19:50:50 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "AForm.hpp"
// #include "Bureaucrat.hpp"
// #include "Intern.hpp"
// #include <cstdlib>
// #include <ctime>
// #include <iostream>

// int main() {
//   std::srand(std::time(0));
//   std::cout << "\n--- Creating Bureaucrats & Intern ---" << std::endl;
//   Bureaucrat boss("Boss", 1);
//   Intern someRandomIntern;
//   AForm *rrf = NULL;
//   AForm *scf = NULL;
//   AForm *ppf = NULL;
//   AForm *unknown = NULL;

//   std::cout << "\n--- Intern tries to create forms ---" << std::endl;
//   rrf = someRandomIntern.makeForm("robotomy request", "Bender");
//   scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
//   ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
//   unknown = someRandomIntern.makeForm("coffee request", "Boss");

//   std::cout << "\n--- Bureaucrat signs and executes created forms ---"
//             << std::endl;
//   if (rrf) {
//     boss.signForm(*rrf);
//     boss.executeForm(*rrf);
//     delete rrf;
//   }

//   if (scf) {
//     boss.signForm(*scf);
//     boss.executeForm(*scf);
//     delete scf;
//   }

//   if (ppf) {
//     boss.signForm(*ppf);
//     boss.executeForm(*ppf);
//     delete ppf;
//   }

//   if (unknown) {
//     delete unknown;
//   }

//   std::cout << "\n--- Cleaning up ---" << std::endl;
//   return 0;
// }


#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    std::cout << MAGENTA << "--- STEP 1: Bureaucrat Setup ---" << RESET << std::endl;
    Bureaucrat boss("Boss", 1);
    Bureaucrat assistant("Assistant", 45);
    Bureaucrat intern("Intern", 150);
    std::cout << boss << "\n" << assistant << "\n" << intern << std::endl;

    // --- TEST 1: ShrubberyCreationForm ---
    std::cout << YELLOW << "\n--- TEST 1: Shrubbery (Sign 145, Exec 137) ---" << RESET << std::endl;
    {
        ShrubberyCreationForm shrub("home");
        std::cout << shrub << std::endl;
        
        intern.signForm(shrub);    // Fail: 150 > 145
        assistant.signForm(shrub); // Success: 45 <= 145
        
        std::cout << "> Execution test:" << std::endl;
        intern.executeForm(shrub);    // Fail: 150 > 137
        assistant.executeForm(shrub); // Success: Creates home_shrubbery
    }

    // --- TEST 2: RobotomyRequestForm ---
    std::cout << YELLOW << "\n--- TEST 2: Robotomy (Sign 72, Exec 45) ---" << RESET << std::endl;
    {
        RobotomyRequestForm robot("Bender");
        assistant.signForm(robot); // Success: 45 <= 72
        
        std::cout << "> Execution (50% chance test):" << std::endl;
        assistant.executeForm(robot); // Success: 45 <= 45
        boss.executeForm(robot);      // Randomness check
    }

    // --- TEST 3: PresidentialPardonForm ---
    std::cout << YELLOW << "\n--- TEST 3: Presidential Pardon (Sign 25, Exec 5) ---" << RESET << std::endl;
    {
        PresidentialPardonForm pardon("Marvin");
        assistant.signForm(pardon); // Fail: 45 > 25
        boss.signForm(pardon);      // Success: 1 <= 25
        
        std::cout << "> Execution test:" << std::endl;
        assistant.executeForm(pardon); // Fail: 45 > 5
        boss.executeForm(pardon);      // Success: 1 <= 5
    }

    // --- TEST 4: Execution without signature ---
    std::cout << YELLOW << "\n--- TEST 4: Executing unsigned form ---" << RESET << std::endl;
    {
        PresidentialPardonForm unsignedForm("Target");
        boss.executeForm(unsignedForm); // Should fail: Not signed
    }

    std::cout << MAGENTA << "\n--- End of ex02 tests ---" << RESET << std::endl;
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
      │ virtual executeAction() const = 0│      Calls AForm::execute(*this)
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

- AForm: Renamed from Form, now abstract (contains pure virtual). 
- Base attributes: Remain private in AForm as per requirements.
- AForm::execute(): Validates TWO conditions before action:
    1. The form is signed.
    2. The executor's grade is high enough.
- Concrete Classes: Implement specific requirements:
    * Shrubbery: Writes ASCII trees to <target>_shrubbery.
    * Robotomy: Makes noises and succeeds 50% of the time.
    * Pardon: Informs about Zaphod Beeblebrox's pardon.
- Bureaucrat::executeForm(): Professional wrapper that attempts
  execution and handles feedback/errors.
*/