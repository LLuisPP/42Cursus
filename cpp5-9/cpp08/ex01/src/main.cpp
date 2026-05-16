/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:00:00 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/10 10:00:00 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

static void	testSubject(void)
{
	std::cout << BY << "\n--- Subject test ---" << RES << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

static void	testOverflow(void)
{
	std::cout << BY << "\n--- Overflow test ---" << RES << std::endl;
	Span sp = Span(3);
	try
	{
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
	}
	catch (std::exception &e)
	{
		std::cout << BR << "Exception: " << e.what() << RES << std::endl;
	}
}

static void	testTooFew(void)
{
	std::cout << BY << "\n--- Too few elements test ---" << RES << std::endl;

	Span sp0 = Span(5);
	try
	{
		std::cout << sp0.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BR << "Exception (0 elements): " << e.what()
			<< RES << std::endl;
	}

	Span sp1 = Span(5);
	sp1.addNumber(42);
	try
	{
		std::cout << sp1.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BR << "Exception (1 element): " << e.what()
			<< RES << std::endl;
	}
}

static void	testLargeSpan(void)
{
	std::cout << BY << "\n--- Large span test (10,000 numbers) ---"
		<< RES << std::endl;
	Span sp = Span(10000);

	std::srand(static_cast<unsigned int>(std::time(NULL)));
	for (int i = 0; i < 10000; i++)
		sp.addNumber(std::rand());

	std::cout << GY << "Shortest span: " << BGR << sp.shortestSpan()
		<< RES << std::endl;
	std::cout << GY << "Longest span:  " << BGR << sp.longestSpan()
		<< RES << std::endl;
}

static void	testRangeAdd(void)
{
	std::cout << BY << "\n--- Range add test ---" << RES << std::endl;
	Span sp = Span(10);

	std::vector<int> vec;
	for (int i = 0; i < 5; i++)
		vec.push_back(i * 100);

	sp.addRange(vec.begin(), vec.end());
	std::cout << GY << "After adding range [0,100,200,300,400]:" << RES
		<< std::endl;
	std::cout << GY << "Shortest span: " << BGR << sp.shortestSpan()
		<< RES << std::endl;
	std::cout << GY << "Longest span:  " << BGR << sp.longestSpan()
		<< RES << std::endl;

	try
	{
		std::vector<int> bigVec;
		for (int i = 0; i < 10; i++)
			bigVec.push_back(i);
		sp.addRange(bigVec.begin(), bigVec.end());
	}
	catch (std::exception &e)
	{
		std::cout << BR << "Exception (range overflow): " << e.what()
			<< RES << std::endl;
	}
}

static void	testCopyAssign(void)
{
	std::cout << BY << "\n--- Copy & assignment test ---" << RES << std::endl;
	Span original = Span(5);
	original.addNumber(1);
	original.addNumber(100);

	Span copied(original);
	std::cout << GY << "Copied shortest: " << BGR << copied.shortestSpan()
		<< RES << std::endl;
	std::cout << GY << "Copied longest:  " << BGR << copied.longestSpan()
		<< RES << std::endl;

	Span assigned = Span(1);
	assigned = original;
	std::cout << GY << "Assigned shortest: " << BGR << assigned.shortestSpan()
		<< RES << std::endl;
	std::cout << GY << "Assigned longest:  " << BGR << assigned.longestSpan()
		<< RES << std::endl;
}

int	main(void)
{
	std::cout << BB << BD << "=== SPAN TESTS ===" << RES << std::endl;
	testSubject();
	testOverflow();
	testTooFew();
	testLargeSpan();
	testRangeAdd();
	testCopyAssign();
	std::cout << std::endl;
	return (0);
}
