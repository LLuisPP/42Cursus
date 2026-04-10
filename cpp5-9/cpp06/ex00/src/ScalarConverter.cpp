/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:50:34 by lprieto-          #+#    #+#             */
/*   Updated: 2026/04/10 21:50:35 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { *this = src; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) { (void)rhs; return (*this); }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &s) {
	double d = 0.0;
	bool isSpecial = false;

	if (s.length() == 1 && !isdigit(s[0]) && isprint(s[0])) {
		d = static_cast<double>(s[0]);
	} else if (s == "-inff" || s == "+inff" || s == "nanf" ||
						 s == "-inf" || s == "+inf" || s == "nan") {
		isSpecial = true;
		if (s == "nan" || s == "nanf") d = std::numeric_limits<double>::quiet_NaN();
		else if (s[0] == '+') d = std::numeric_limits<double>::infinity();
		else d = -std::numeric_limits<double>::infinity();
	} else {
		char *endptr;
		d = std::strtod(s.c_str(), &endptr);
		if (*endptr != '\0') {
			if (!(*endptr == 'f' && *(endptr + 1) == '\0')) {
				// invalid literal
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				return;
			}
		}
	}

	// char
	std::cout << "char: ";
	if (isSpecial || d != d || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max()) {
		std::cout << "impossible" << std::endl;
	} else {
		char c = static_cast<char>(d);
		if (!isprint(c)) std::cout << "Non displayable" << std::endl;
		else std::cout << "'" << c << "'" << std::endl;
	}

	// int
	std::cout << "int: ";
	if (isSpecial || d != d || d < -2147483648.0 || d > 2147483647.0) {
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << static_cast<int>(d) << std::endl;
	}

	// float
	std::cout << "float: ";
	if (isSpecial) {
		if (s == "nan" || s == "nanf") std::cout << "nanf" << std::endl;
		else if (s[0] == '+') std::cout << "+inff" << std::endl;
		else std::cout << "-inff" << std::endl;
	} else {
		float f = static_cast<float>(d);
		// Print f with exactly 1 decimal unless it already has more.
		// wait, how to mimic setprecision(1) only for `.0`?
		// "fixed" and "setprecision(1)" does it.
		// But if value is 42.5, it prints 42.5.
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}

	// double
	std::cout << "double: ";
	if (isSpecial) {
		if (s == "nan" || s == "nanf") std::cout << "nan" << std::endl;
		else if (s[0] == '+') std::cout << "+inf" << std::endl;
		else std::cout << "-inf" << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	}
}
