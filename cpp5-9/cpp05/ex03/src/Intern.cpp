/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:14:07 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/10 20:14:08 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern() {
  std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern &src) {
  std::cout << "Intern Copy Constructor called" << std::endl;
  *this = src;
}

Intern &Intern::operator=(const Intern &src) {
  std::cout << "Intern Assignation operator called" << std::endl;
  (void)src; // Intern has no state
  return *this;
}

Intern::~Intern() { std::cout << "Intern Destructor called" << std::endl; }

AForm *Intern::_makeShrubbery(std::string target) const {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::_makeRobotomy(std::string target) const {
  return new RobotomyRequestForm(target);
}

AForm *Intern::_makePresidential(std::string target) const {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target) const {
  std::string names[3] = {"shrubbery creation", "robotomy request",
                          "presidential pardon"};
  AForm *(Intern::*funcs[3])(std::string)
      const = {&Intern::_makeShrubbery, &Intern::_makeRobotomy,
               &Intern::_makePresidential};

  for (int i = 0; i < 3; i++) {
    if (formName == names[i]) {
      std::cout << "Intern creates " << formName << std::endl;
      return (this->*funcs[i])(target);
    }
  }

  std::cerr << "Error: Intern cannot create '" << formName
            << "' because it is unknown." << std::endl;
  return NULL; // Null pointer indicates failure
}
