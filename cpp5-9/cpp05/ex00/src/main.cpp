/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 12:34:16 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/09 18:59:51 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
  // - - - [Valid construction] - - -
  // Bureaucrat with grade in valid range [1, 150]
  std::cout << "\n - - - [Valid construction] - - -\n";
  try {
    Bureaucrat b("Alice", 75);
    std::cout << b << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  // - - - [GradeTooHighException] - - -
  // Grade 0 is above the maximum allowed (1)
  std::cout << "\n - - - [GradeTooHighException] - - -\n";
  try {
    Bureaucrat b("Bob", 0);
    std::cout << b << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  // - - - [GradeTooLowException] - - -
  // Grade 151 is below the minimum allowed (150)
  std::cout << "\n - - - [GradeTooLowException] - - -\n";
  try {
    Bureaucrat b("Charlie", 151);
    std::cout << b << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  // - - - [incrementGrade] - - -
  // Grade goes from 3 to 1, then tries to go above 1 → exception
  std::cout << "\n - - - [incrementGrade] - - -\n";
  try {
    Bureaucrat b("Dave", 3);
    std::cout << b << std::endl;
    b.incrementGrade();
    std::cout << b << std::endl;
    b.incrementGrade();
    std::cout << b << std::endl;
    b.incrementGrade(); // grade would become 0 → throws
    std::cout << b << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  // - - - [decrementGrade] - - -
  // Grade goes from 148 to 150, then tries to go below 150 → exception
  std::cout << "\n - - - [decrementGrade] - - -\n";
  try {
    Bureaucrat b("Eve", 148);
    std::cout << b << std::endl;
    b.decrementGrade();
    std::cout << b << std::endl;
    b.decrementGrade();
    std::cout << b << std::endl;
    b.decrementGrade(); // grade would become 151 → throws
    std::cout << b << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  return (0);
}

/*
        Bureaucrat
     ┌───────────────────┐
     │ _name (const)     │  private
     │ _grade            │  private, range [1..150]
     ├───────────────────┤
     │ getName()         │  getter
     │ getGrade()        │  getter
     │ incrementGrade()  │  grade-- (throws if < 1)
     │ decrementGrade()  │  grade++ (throws if > 150)
     └───────────────────┘
            │ nested classes
     ┌──────┴──────────────────┐
     │                         │
┌────┴──────────────┐  ┌───────┴──────────────┐
│ GradeTooHigh      │  │ GradeTooLow           │
│ Exception         │  │ Exception             │
│ what() → "..."    │  │ what() → "..."        │
└───────────────────┘  └──────────────────────┘

Bureaucrat holds a const name and an int grade.
Grade 1 is the highest rank, grade 150 the lowest.
Attempting to construct or modify a Bureaucrat outside
this range throws a nested exception class that inherits
from std::exception and overrides what().
incrementGrade() subtracts 1 (moving up in hierarchy),
decrementGrade() adds 1 (moving down).
operator<< prints: "<name>, bureaucrat grade <grade>".
*/
