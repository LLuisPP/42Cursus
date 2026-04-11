/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:14:00 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/11 20:04:25 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
  std::cout << "AForm Default Constructor called for " << this->getName() << std::endl;
}

AForm::AForm(const AForm &src) : _name(src.getName()), _isSigned(src.isSigned()),_gradeToSign(src.getGradeToSign()),_gradeToExecute(src.getGradeToExecute()) {
	std::cout << "AForm Copy Constructor called" << std::endl;
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "AForm Constructor called for " << this->getName() << std::endl;
}

AForm &AForm::operator=(const AForm &src) {
	std::cout << "AForm Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	this->_isSigned = src.isSigned();
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm Destructor for " << this->getName() << " called" << std::endl;
}

void AForm::beSigned(Bureaucrat &b) {
	if (b.getGrade() > this->_gradeToSign) {
		throw GradeTooLowException();
	}
	this->_isSigned = true;
}

void AForm::checkRequirements(Bureaucrat const &executor) const {
	if (!this->isSigned())
		throw NotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();
}

const std::string AForm::getName() const { return this->_name; }

bool AForm::isSigned() const {
	return this->_isSigned;
}

int AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "\033[31mGrade is too low!\033[0m";
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "\033[31mGrade is too high!\033[0m";
}

const char *AForm::NotSignedException::what() const throw() {
	return "\033[31mForm is not signed!\033[0m";
}

std::ostream &operator<<(std::ostream &o, const AForm &f) {
	o << "- AForm: " << f.getName() << "\n"
    << "- Signed: " << (f.isSigned() ? "Yes" : "No") << "\n"
    << "- Grade required to sign: " << f.getGradeToSign() << "\n"
    << "- Grade required to execute: " << f.getGradeToExecute();
	return o;
}
