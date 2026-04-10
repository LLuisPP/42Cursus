/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:12:11 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/10 20:12:13 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        Form();
        Form(const Form &src);
        Form(const std::string name, int gradeToSign, int gradeToExecute);
        Form &operator=(const Form &src);
        ~Form();

        void beSigned(Bureaucrat &b);

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
};

std::ostream &operator<<(std::ostream &o, const Form &f);

#endif
