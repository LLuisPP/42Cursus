/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 20:53:49 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/01 20:53:51 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
    
    for (int i = 0; i < 100; i++) {
        _ideas[i] = "Idea . .";
    }
    std::cout << PP << "Brain" << G << " 🧠 created !?" << RES << std::endl;
}

Brain::Brain(const Brain &copy) {

    for (int i = 0; i < 100; i++) {
        _ideas[i] = copy._ideas[i];
    };
    std::cout << PP << "Brain" << G << " 🧠 created !?" << RES << std::endl;
}

Brain &Brain::operator=(const Brain &copy) {

    for (int i = 0; i < 100; i++) {
        _ideas[i] = copy._ideas[i];
    };
    std::cout << PP << "Brain" << G << " 🧠 created !?" << RES << std::endl;
    return (*this);
}

Brain::~Brain(void) {

    std::cout << PP << "Brain" << R << " destroyed" << RES << std::endl;
}

std::string	*Brain::getIdeas(void) {
 
    return (_ideas);
}

void    Brain::setIdea(std::string idea, int i) {

    _ideas[i] = idea;
}