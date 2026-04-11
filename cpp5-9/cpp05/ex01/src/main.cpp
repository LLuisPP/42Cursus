/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:12:29 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/11 21:22:31 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) {
    // --- Test 1: Standard Form Creation ---
    std::cout << "--- Test 1:" << YELLOW << " Create valid Form (Sign 100, Exec 50) ---" << RESET << std::endl;
    try {
        Form f1("Tax Form", 100, 50);
        std::cout << f1 << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // --- Test 2: Invalid Form (Grade too High) ---
    std::cout << "\n--- Test 2:" << YELLOW << " Invalid Form (Grade 0) ---" << RESET << std::endl;
    try {
        Form f2("Top Secret", 0, 50);
        std::cout << f2 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // --- Test 3: Invalid Form (Grade too Low) ---
    std::cout << "\n--- Test 3:" << YELLOW << " Invalid Form (Grade 151) ---" << RESET << std::endl;
    try {
        Form f3("Garbage Form", 151, 50);
        std::cout << f3 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // --- Test 4: Successful Signing ---
    std::cout << "\n--- Test 4:" << YELLOW << " Bureaucrat signs Form (Success) ---" << RESET << std::endl;
    try {
        Bureaucrat b1("Alice", 50);
        Form f4("NDA", 100, 50);
        
        std::cout << "> Initial state:" << std::endl;
        std::cout << "  " << b1 << std::endl;
        std::cout << "  " << f4 << std::endl;
        
        std::cout << "> Action:" << std::endl;
        b1.signForm(f4); // This calls f4.beSigned(b1)
        
        std::cout << "> Result:" << std::endl;
        std::cout << f4 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // --- Test 5: Failed Signing ---
    std::cout << "\n--- Test 5:" << YELLOW << " Bureaucrat signs Form (Fail: Grade too low) ---" << RESET << std::endl;
    try {
        Bureaucrat b2("Bob", 120);
        Form f5("Contract", 100, 50);
        
        std::cout << "> Initial state:" << std::endl;
        std::cout << b2 << std::endl;
        std::cout << f5 << std::endl;
        
        std::cout << "> Action:" << std::endl;
        b2.signForm(f5); // Should print the "reason" why 
        
        std::cout << "> Result:" << std::endl;
        std::cout << f5 << std::endl;
    } catch (std::exception &e) {
        // This catch is a safety net, signForm should handle the message internally
        std::cout << RED << "Unexpected Exception: " << e.what() << RESET << std::endl;
    }

    return (0);
}

/*
        Form (Class)                           Bureaucrat (Class)
    ┌───────────────────────────┐           ┌───────────────────────────┐
    │ _name (const)             │           │ _name (const)             │
    │ _isSigned (bool)          │           │ _grade [1..150]           │
    │ _gradeToSign (const)      │           ├───────────────────────────┤
    │ _gradeToExecute (const)   │           │ signForm(Form &)          │
    ├───────────────────────────┤           └─────────────┬─────────────┘
    │ getName()                 │                         │
    │ getIsSigned()             │                         │
    │ getGradeToSign()          │                         │
    │ getGradeToExecute()       │           Calls beSigned(*this)
    │ beSigned(Bureaucrat &)    │<────────────────────────┘
    └─────────────┬─────────────┘
                  │ nested classes
    ┌─────────────┴─────────────┐
    │ GradeTooHighException     │   Inherit from std::exception
    │ GradeTooLowException      │   Override what()
    └───────────────────────────┘

- Form attributes are private, not protected.
- A Form is not signed upon construction.
- Grades follow the same logic: 1 (highest) to 150 (lowest).
- beSigned(): Changes status to signed if Bureaucrat's grade is high 
  enough (grade <= _gradeToSign), otherwise throws GradeTooLowException.
- Bureaucrat::signForm(): Attempts to sign and prints the result:
    Success: "<bureaucrat> signed <form>".
    Failure: "<bureaucrat> couldn't sign <form> because <reason>".
- operator<< prints all form information.
*/