/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:13:41 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/10 20:13:42 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern {
    private:
        AForm* _makeShrubbery(std::string target) const;
        AForm* _makeRobotomy(std::string target) const;
        AForm* _makePresidential(std::string target) const;

    public:
        Intern();
        Intern(const Intern &src);
        Intern &operator=(const Intern &src);
        ~Intern();

        AForm* makeForm(std::string formName, std::string target) const;
};

#endif
