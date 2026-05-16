/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:00:00 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/10 10:00:00 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const std::string &dbFile)
{
	if (!_loadDatabase(dbFile))
		throw std::runtime_error("Error: could not open database file.");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
	: _database(copy._database) {}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
		_database = copy._database;
	return (*this);
}

bool	BitcoinExchange::_loadDatabase(const std::string &filename)
{
	std::ifstream	file(filename.c_str());

	if (!file.is_open())
		return (false);

	std::string	line;
	std::getline(file, line); // skip header "date,exchange_rate"
	while (std::getline(file, line))
	{
		std::string::size_type	pos = line.find(',');
		if (pos == std::string::npos)
			continue ;
		std::string	date = line.substr(0, pos);
		std::string	rateStr = line.substr(pos + 1);
		float		rate = static_cast<float>(std::atof(rateStr.c_str()));
		_database[date] = rate;
	}
	file.close();
	return (true);
}

bool	BitcoinExchange::_isValidDate(const std::string &date) const
{
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (date[i] < '0' || date[i] > '9')
			return (false);
	}
	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());
	if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	if (month == 2)
	{
		bool	isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (isLeap ? 29 : 28))
			return (false);
	}
	return (true);
}

float	BitcoinExchange::_getExchangeRate(const std::string &date) const
{
	std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
	if (it != _database.end() && it->first == date)
		return (it->second);
	if (it == _database.begin())
		throw std::runtime_error("Error: date is before database records.");
	--it;
	return (it->second);
}

void	BitcoinExchange::processInputFile(const std::string &inputFile) const
{
	std::ifstream	file(inputFile.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}

	std::string	line;
	std::getline(file, line); // skip header "date | value"
	while (std::getline(file, line))
	{
		std::string::size_type	pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		std::string	date = line.substr(0, pipePos);
		std::string	valueStr = line.substr(pipePos + 1);

		// Trim whitespace
		while (!date.empty() && date[date.size() - 1] == ' ')
			date.erase(date.size() - 1);
		while (!valueStr.empty() && valueStr[0] == ' ')
			valueStr.erase(0, 1);

		if (!_isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue ;
		}

		char	*endPtr;
		float	value = static_cast<float>(std::strtod(valueStr.c_str(), &endPtr));
		if (*endPtr != '\0' && *endPtr != '\r')
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}

		try
		{
			float	rate = _getExchangeRate(date);
			float	result = value * rate;
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	file.close();
}
