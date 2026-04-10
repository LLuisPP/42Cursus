/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:14:27 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/10 20:14:28 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
  std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
  std::cout << "ShrubberyCreationForm Constructor called for target " << _target
            << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src), _target(src._target) {
  std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
  std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
  if (this == &src)
    return *this;
  AForm::operator=(src);
  this->_target = src._target;
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  this->checkRequirements(
      executor); // Will throw if not signed or grade too low

  std::string filename = this->_target + "_shrubbery";
  std::ofstream outfile(filename.c_str());
  if (!outfile.is_open()) {
    std::cerr << "Error: Could not open file " << filename << std::endl;
    return;
  }

  outfile << "       _-_" << std::endl;
  outfile << "    /~~   ~~\\" << std::endl;
  outfile << " /~~         ~~\\" << std::endl;
  outfile << "{               }" << std::endl;
  outfile << " \\  _-     -_  /" << std::endl;
  outfile << "   ~  \\\\ //  ~" << std::endl;
  outfile << "_- -   | | _- _" << std::endl;
  outfile << "  _ -  | |   -_" << std::endl;
  outfile << "      // \\\\" << std::endl;
  outfile.close();
}
