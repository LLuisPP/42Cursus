/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:00:00 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/10 10:00:00 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN &copy) : _stack(copy._stack) {}

RPN::~RPN(void) {}

RPN &RPN::operator=(const RPN &copy)
{
	if (this != &copy)
		_stack = copy._stack;
	return (*this);
}

bool	RPN::_isOperator(const std::string &token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int	RPN::_applyOperator(int a, int b, const std::string &op) const
{
	if (op == "+")
		return (a + b);
	if (op == "-")
		return (a - b);
	if (op == "*")
		return (a * b);
	if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("Error: division by zero.");
		return (a / b);
	}
	throw std::runtime_error("Error: unknown operator.");
}

int	RPN::evaluate(const std::string &expression)
{
	std::istringstream	iss(expression);
	std::string			token;

	while (iss >> token)
	{
		if (_isOperator(token))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error");
			int	b = _stack.top();
			_stack.pop();
			int	a = _stack.top();
			_stack.pop();
			_stack.push(_applyOperator(a, b, token));
		}
		else
		{
			// Validate that token is a single digit number (< 10)
			if (token.length() > 1 && !(token.length() == 2 && token[0] == '-'))
				throw std::runtime_error("Error");
			for (size_t i = 0; i < token.length(); i++)
			{
				if (i == 0 && token[i] == '-' && token.length() > 1)
					continue ;
				if (token[i] < '0' || token[i] > '9')
					throw std::runtime_error("Error");
			}
			int	num = std::atoi(token.c_str());
			if (num >= 10 || num <= -10)
				throw std::runtime_error("Error");
			_stack.push(num);
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error");
	return (_stack.top());
}
