/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:13:21 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/11 19:23:25 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {
    std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm Constructor called for target " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target) {
    std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
    std::cout << "RobotomyRequestForm Assignation operator called" << std::endl;
    if (this == &src)
        return *this;
    AForm::operator=(src);
    this->_target = src._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    this->checkRequirements(executor);
    
    std::cout << "*" << YELLOW << " BZZZZZT... DRILLING INTENSIFIES... VZZZZZZ... " << RESET << "*" << std::endl;
    
    if (std::rand() % 2 == 0) {
        std::cout << this->_target << GREEN << " has been robotomized successfully!" << RESET << std::endl;
    } else {
        std::cout << RED << "Robotomy failed on " << this->_target << RESET << "!" << std::endl;
    }
}
