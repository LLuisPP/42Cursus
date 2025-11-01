/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 12:56:37 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/01 12:56:40 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal() {

    _type = "Cat";
    std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat &copy): Animal() {

    _type = copy._type;
    std::cout << "Cat created" << std::endl;
}

Cat &Cat::operator=(const Cat &copy) {

    _type = copy._type;
    std::cout << "Cat created" << std::endl;
    return (*this);
}

Cat::~Cat(void) {

    std::cout << "Cat destroyed" << std::endl;
}

void    Cat::makeSound(void) {

    std::cout << "meeeeeeeew" << std::endl;
}