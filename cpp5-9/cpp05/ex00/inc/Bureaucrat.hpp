/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:15:09 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/11 18:46:34 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

class Bureaucrat {

	private:
		const	std::string	_name;
		int		_grade;

	public:

		Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat();

		void	incrementGrade(void);
		void	decrementGrade(void);

		const	std::string getName(void)const;

		int		getGrade(void) const;


	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	
	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &a);

#endif
