/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:12:35 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/10 20:12:36 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        AForm();
        AForm(const AForm &src);
        AForm(const std::string name, int gradeToSign, int gradeToExecute);
        AForm &operator=(const AForm &src);
        virtual ~AForm();

        void beSigned(Bureaucrat &b);
        virtual void execute(Bureaucrat const & executor) const = 0; // Pure virtual makes it abstract
        void checkRequirements(Bureaucrat const & executor) const; // Helper

        const std::string getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class NotSignedException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &o, const AForm &f);

#endif
