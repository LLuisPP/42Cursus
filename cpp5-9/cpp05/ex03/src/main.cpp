/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:14:12 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/10 20:14:13 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  std::srand(std::time(0));
  std::cout << "\n--- Creating Bureaucrats & Intern ---" << std::endl;
  Bureaucrat boss("Boss", 1);
  Intern someRandomIntern;
  AForm *rrf = NULL;
  AForm *scf = NULL;
  AForm *ppf = NULL;
  AForm *unknown = NULL;

  std::cout << "\n--- Intern tries to create forms ---" << std::endl;
  rrf = someRandomIntern.makeForm("robotomy request", "Bender");
  scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
  ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
  unknown = someRandomIntern.makeForm("coffee request", "Boss");

  std::cout << "\n--- Bureaucrat signs and executes created forms ---"
            << std::endl;
  if (rrf) {
    boss.signForm(*rrf);
    boss.executeForm(*rrf);
    delete rrf;
  }

  if (scf) {
    boss.signForm(*scf);
    boss.executeForm(*scf);
    delete scf;
  }

  if (ppf) {
    boss.signForm(*ppf);
    boss.executeForm(*ppf);
    delete ppf;
  }

  if (unknown) {
    delete unknown;
  }

  std::cout << "\n--- Cleaning up ---" << std::endl;
  return 0;
}
