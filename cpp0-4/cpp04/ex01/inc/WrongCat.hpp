/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:03:01 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/01 13:03:05 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class   WrongCat: public WrongAnimal {

    public:
        WrongCat(void);
        WrongCat(const WrongCat &copy);
        WrongCat    &operator=(const WrongCat &copy);
        ~WrongCat(void);

        void    makeSound(void);
};

#endif