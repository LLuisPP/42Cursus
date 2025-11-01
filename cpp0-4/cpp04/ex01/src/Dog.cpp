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
    _brain = new Brain();
    std::cout << B <<"Dog" << RES << " created" << std::endl;
}

Dog::Dog(const Dog &copy): Animal() {

    _type = copy._type;
    _brain = new Brain(*copy._brain);
    std::cout << B <<"Dog" << RES << " created copy" << std::endl;
}

Dog &Dog::operator=(const Dog &copy) {

    _type = copy._type;
    *_brain = *copy._brain;
    std::cout << B <<"Dog" << RES << " created assign" << std::endl;
    return (*this);
}

Dog::~Dog(void) {

    std::cout << B << "Dog" << R << " destroyed" << RES << std::endl;
}

void    Dog::makeSound(void) {

    std::cout << B << "Wooof Wooof" << std::endl;
}

Brain   *Dog::getBrain(void) {

    return (_brain);
}