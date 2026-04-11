/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 12:34:16 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/11 18:46:20 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
    // --- Test 1: Standard bureaucrat ---
    std::cout << "--- Test 1:" << YELLOW << " Valid range (Grade 75) ---" << RESET << std::endl;
	
    try {
        Bureaucrat b("Alice", 75);
        std::cout << GREEN << b << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // --- Test 2: Grade too high ---
    std::cout << "\n--- Test 2:" << YELLOW << " Grade too high (Grade 0) ---" << RESET << std::endl;

    try {
        Bureaucrat b("Bob", 0);
        std::cout << b << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // --- Test 3: Grade too low ---
    std::cout << "\n--- Test 3:" << YELLOW << " Grade too low (Grade 151) ---" << RESET << std::endl;

    try {
        Bureaucrat b("Charlie", 151);
        std::cout << b << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // --- Test 4: Increment/Decrement boundaries ---
    std::cout << "\n--- Test 4:" << YELLOW << " Increment/Decrement boundaries ---" << RESET << std::endl;

    try {
        Bureaucrat b("Dave", 2);
        std::cout << "> Initial: " << b << std::endl;
        b.incrementGrade();
        std::cout << GREEN << b << RESET << std::endl;
        std::cout << "> Attempting invalid increment..." << std::endl;
        b.incrementGrade(); // This should throw
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
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
│ GradeTooHigh      │  │ GradeTooLow          │
│ Exception         │  │ Exception            │
│ what() → "..."    │  │ what() → "..."       │
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
