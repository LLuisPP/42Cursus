/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:00:00 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/10 10:00:00 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &copy) : _maxSize(copy._maxSize), _numbers(copy._numbers) {}

Span::~Span(void) {}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		_maxSize = copy._maxSize;
		_numbers = copy._numbers;
	}
	return (*this);
}

void	Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw std::overflow_error("Span is full: cannot add more numbers");
	_numbers.push_back(number);
}

int	Span::shortestSpan(void) const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough elements to find a span");

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int	minSpan = INT_MAX;
	for (size_t i = 1; i < sorted.size(); i++)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < minSpan)
			minSpan = diff;
	}
	return (minSpan);
}

int	Span::longestSpan(void) const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough elements to find a span");

	int	minVal = *std::min_element(_numbers.begin(), _numbers.end());
	int	maxVal = *std::max_element(_numbers.begin(), _numbers.end());
	return (maxVal - minVal);
}
