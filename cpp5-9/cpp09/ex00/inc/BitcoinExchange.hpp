/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:00:00 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/10 10:00:00 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

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

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange {

	private:
		std::map<std::string, float>	_database;

		bool	_loadDatabase(const std::string &filename);
		bool	_isValidDate(const std::string &date) const;
		float	_getExchangeRate(const std::string &date) const;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const std::string &dbFile);
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange(void);

		BitcoinExchange &operator=(const BitcoinExchange &copy);

		void	processInputFile(const std::string &inputFile) const;
};

#endif
