/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:12:24 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/11 19:05:11 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "Form Default Constructor called for " << this->getName() << std::endl;
}

Form::Form(const Form &src) : _name(src.getName()), _isSigned(src.isSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute()) {
    std::cout << "Form Copy Constructor called" << std::endl;
}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "Form Constructor called for " << this->getName() << std::endl;
}

Form &Form::operator=(const Form &src) {
    std::cout << "Form Assignation operator called" << std::endl;
    if (this == &src)
        return *this;
    this->_isSigned = src.isSigned();
    return *this;
}

Form::~Form() {
    std::cout << "Form Destructor for " << this->getName() << " called" << std::endl;
}

void Form::beSigned(Bureaucrat &b) {
    if (b.getGrade() > this->_gradeToSign) {
        throw GradeTooLowException();
    }
    this->_isSigned = true;
}

const std::string Form::getName() const {
    return this->_name;
}

bool Form::isSigned() const {
    return this->_isSigned;
}

int Form::getGradeToSign() const {
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
    return this->_gradeToExecute;
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

std::ostream &operator<<(std::ostream &o, const Form &f) {
	o << "  - Form: " << f.getName() << "\n"
      << "  - Signed: " << (f.isSigned() ? "\033[32mYes\033[0m" : "\033[31mNo\033[0m") << "\n"
      << "  - Grade required to sign: " << f.getGradeToSign() << "\n"
      << "  - Grade required to execute: " << f.getGradeToExecute();
	return o;
}
