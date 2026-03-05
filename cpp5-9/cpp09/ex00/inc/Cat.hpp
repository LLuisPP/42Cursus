/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 12:40:38 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/01 12:42:56 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal {

	public:
		Cat(void);
		Cat(const Cat &copy);
		Cat &operator=(const Cat &copy);
		~Cat(void);

		void	makeSound(void);
};

#endif
