/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 07:37:24 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/23 09:34:13 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {

	private:
		std::string name;

	public:
		Zombie(std::string);
		~Zombie(void);
		void	announce(void);
};

Zombie	*newZombie(std::string);
void	randomChump(std::string);

#endif
