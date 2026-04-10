/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:12:29 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/10 20:12:30 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "\n--- Creating Forms ---" << std::endl;
    try {
        Form f1("Tax Form", 100, 50);
        std::cout << f1 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Invalid Form (Too High Grade) ---" << std::endl;
    try {
        Form f2("Top Secret", 0, 50);
        std::cout << f2 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Invalid Form (Too Low Grade) ---" << std::endl;
    try {
        Form f3("Garbage Form", 151, 50);
        std::cout << f3 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Bureaucrat Signing Form (Success) ---" << std::endl;
    try {
        Bureaucrat b1("Alice", 50);
        Form f4("NDA", 100, 50);
        std::cout << b1 << std::endl;
        std::cout << f4 << std::endl;
        b1.signForm(f4);
        std::cout << f4 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Bureaucrat Signing Form (Fail) ---" << std::endl;
    try {
        Bureaucrat b2("Bob", 120);
        Form f5("Contract", 100, 50);
        std::cout << b2 << std::endl;
        std::cout << f5 << std::endl;
        b2.signForm(f5);
        std::cout << f5 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
