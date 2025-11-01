/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 12:45:29 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/01 12:48:48 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

// Color macros:
#define RES	"\033[0m"
#define BGY	"\033[1;90m"
#define BR	"\033[1;91m"
#define BGR	"\033[1;92m"
#define BY	"\033[1;33m"
#define BB	"\033[1;94m"
#define BC	"\033[1;96m"
#define BW	"\033[1;97m"
#define GY	"\033[0;90m"
#define R	"\033[0;91m"
#define G	"\033[0;92m"
#define Y	"\033[0;93m"
#define B	"\033[0;94m"
#define C	"\033[0;96m"
#define W	"\033[0;97m"
#define PP	"\033[0;95m"
#define BD	"\033[1m"
#define OR	"\033[38;5;214m"
// macros

#include <iostream>

class WrongAnimal {

	protected:
		std::string _type;
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal &operator=(const WrongAnimal &copy);

		virtual ~WrongAnimal(void);
		
		std::string getType(void);
		void	makeSound(void);
};

#endif
