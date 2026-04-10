/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:59:44 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/09 18:47:09 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(1) {
    std::cout << "Bureaucrat Default Constructor called for " << this->getName() << " with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName()), _grade(src.getGrade()) {
    std::cout << "Bureaucrat Copy Constructor called to copy " << src.getName() << " into " << this->getName() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat Constructor called for " << this->getName() << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
    std::cout << "Bureaucrat Assignation operator called" << std::endl;
    if (this == &src)
        return *this;

    this->_grade = src.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat Destructor for " << this->getName() << " called" << std::endl;
}

void Bureaucrat::incrementGrade(void) {
    if (this->_grade - 1 < 1)
        throw GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade(void) {
    if (this->_grade + 1 > 150)
        throw GradeTooLowException();
    this->_grade++;
}

const std::string Bureaucrat::getName(void) const {
    return this->_name;
}

int Bureaucrat::getGrade(void) const {
    return this->_grade;
}



const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &a) {
	o << a.getName() << ", bureaucrat grade " << a.getGrade() << ".";
	return o;
}
