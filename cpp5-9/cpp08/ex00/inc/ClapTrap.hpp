/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:20:27 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/28 08:33:10 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

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

#include <string>

class	ClapTrap {

	private:
		std::string	_name;
		int			_attack;
		int			_energy;
		int			_health;
	public:
		ClapTrap(void);
		explicit ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap(void);
		
		ClapTrap &operator=(const ClapTrap &copy);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
