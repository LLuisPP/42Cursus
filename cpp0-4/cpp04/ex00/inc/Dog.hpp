/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 12:43:08 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/01 12:45:14 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal {

	public:
		Dog(void);
		Dog(const Dog &copy);
		Dog &operator=(const Dog &copy);
		~Dog(void);

		void	makeSound(void);
};

#endif
