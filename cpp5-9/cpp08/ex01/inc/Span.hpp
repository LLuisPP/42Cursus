/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:00:00 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/10 10:00:00 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

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

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <climits>

class Span {

	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:
		Span(void);
		explicit Span(unsigned int n);
		Span(const Span &copy);
		~Span(void);

		Span &operator=(const Span &copy);

		void	addNumber(int number);

		template <typename InputIterator>
		void	addRange(InputIterator begin, InputIterator end)
		{
			unsigned int dist = static_cast<unsigned int>(std::distance(begin, end));
			if (_numbers.size() + dist > _maxSize)
				throw std::overflow_error("Cannot add range: exceeds maximum capacity");
			_numbers.insert(_numbers.end(), begin, end);
		}

		int		shortestSpan(void) const;
		int		longestSpan(void) const;
};

#endif
