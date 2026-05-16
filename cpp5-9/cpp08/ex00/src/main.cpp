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

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

static void	testVector(void)
{
	std::cout << BY << "\n--- Test with std::vector ---" << RES << std::endl;
	std::vector<int>	vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i * 3);

	std::cout << GY << "Vector contents: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << RES << std::endl;

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 9);
		std::cout << BGR << "Found value: " << *it << RES << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BR << "Exception: " << e.what() << RES << std::endl;
	}

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 42);
		std::cout << BGR << "Found value: " << *it << RES << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BR << "Exception: " << e.what() << RES << std::endl;
	}
}

static void	testList(void)
{
	std::cout << BY << "\n--- Test with std::list ---" << RES << std::endl;
	std::list<int>	lst;
	for (int i = 5; i > 0; i--)
		lst.push_back(i * 10);

	std::cout << GY << "List contents: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << RES << std::endl;

	try
	{
		std::list<int>::iterator it = easyfind(lst, 30);
		std::cout << BGR << "Found value: " << *it << RES << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BR << "Exception: " << e.what() << RES << std::endl;
	}

	try
	{
		std::list<int>::iterator it = easyfind(lst, 7);
		std::cout << BGR << "Found value: " << *it << RES << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BR << "Exception: " << e.what() << RES << std::endl;
	}
}

static void	testDeque(void)
{
	std::cout << BY << "\n--- Test with std::deque ---" << RES << std::endl;
	std::deque<int>	deq;
	deq.push_back(-5);
	deq.push_back(0);
	deq.push_back(5);
	deq.push_back(10);
	deq.push_back(15);

	std::cout << GY << "Deque contents: ";
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
		std::cout << *it << " ";
	std::cout << RES << std::endl;

	try
	{
		std::deque<int>::iterator it = easyfind(deq, -5);
		std::cout << BGR << "Found value: " << *it << RES << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BR << "Exception: " << e.what() << RES << std::endl;
	}

	try
	{
		std::deque<int>::iterator it = easyfind(deq, 15);
		std::cout << BGR << "Found value: " << *it << RES << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BR << "Exception: " << e.what() << RES << std::endl;
	}

	try
	{
		std::deque<int>::iterator it = easyfind(deq, 100);
		std::cout << BGR << "Found value: " << *it << RES << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BR << "Exception: " << e.what() << RES << std::endl;
	}
}

static void	testEmpty(void)
{
	std::cout << BY << "\n--- Test with empty container ---" << RES << std::endl;
	std::vector<int>	empty;

	try
	{
		std::vector<int>::iterator it = easyfind(empty, 0);
		std::cout << BGR << "Found value: " << *it << RES << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BR << "Exception: " << e.what() << RES << std::endl;
	}
}

int	main(void)
{
	std::cout << BB << BD << "=== EASYFIND TESTS ===" << RES << std::endl;
	testVector();
	testList();
	testDeque();
	testEmpty();
	std::cout << std::endl;
	return (0);
}
