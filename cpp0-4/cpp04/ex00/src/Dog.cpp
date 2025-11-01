/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:01:29 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/01 13:01:31 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog(void): Animal() {

    _type = "Dog";
    std::cout << B <<"Dog" << RES << " created" << std::endl;
}

Dog::Dog(const Dog &copy): Animal() {

    _type = copy._type;
    std::cout << B <<"Dog" << RES << " created" << std::endl;
}

Dog &Dog::operator=(const Dog &copy) {

    _type = copy._type;
    std::cout << B <<"Dog" << RES << " created" << std::endl;
    return (*this);
}

Dog::~Dog(void) {

    std::cout << B << "Dog" << R << " destroyed" << RES << std::endl;
}

void    Dog::makeSound(void) {

    std::cout << B << "Wooof Wooof" << std::endl;
}