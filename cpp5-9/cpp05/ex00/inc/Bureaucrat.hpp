/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:15:09 by lprieto-          #+#    #+#             */
/*   Updated: 2026/03/25 16:58:25 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

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
