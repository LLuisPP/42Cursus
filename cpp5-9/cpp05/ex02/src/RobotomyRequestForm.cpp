/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:13:21 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/10 20:13:22 by lprieto-         ###   ########.fr       */
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
    
    std::cout << "* BZZZZZT... DRILLING INTENSIFIES... VZZZZZZ... *" << std::endl;
    
    if (std::rand() % 2 == 0) {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << this->_target << "!" << std::endl;
    }
}
