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

#include "MutantStack.hpp"
#include <iostream>
#include <list>

static void	testSubject(void)
{
	std::cout << BY << "\n--- Subject test (MutantStack) ---" << RES
		<< std::endl;

	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

static void	testSubjectList(void)
{
	std::cout << BY << "\n--- Subject test (std::list) ---" << RES
		<< std::endl;

	std::list<int>	mlist;

	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);
	std::list<int>::iterator it = mlist.begin();
	std::list<int>::iterator ite = mlist.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

static void	testReverseIterator(void)
{
	std::cout << BY << "\n--- Reverse iterator test ---" << RES << std::endl;
	MutantStack<int>	mstack;

	for (int i = 1; i <= 5; i++)
		mstack.push(i * 10);

	std::cout << GY << "Forward:  ";
	for (MutantStack<int>::iterator it = mstack.begin();
		it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << RES << std::endl;

	std::cout << GY << "Reverse:  ";
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		rit != mstack.rend(); ++rit)
		std::cout << *rit << " ";
	std::cout << RES << std::endl;
}

static void	testCopyAssign(void)
{
	std::cout << BY << "\n--- Copy & assignment test ---" << RES << std::endl;
	MutantStack<int>	original;
	original.push(42);
	original.push(21);
	original.push(84);

	MutantStack<int>	copied(original);
	std::cout << GY << "Copied stack: ";
	for (MutantStack<int>::iterator it = copied.begin();
		it != copied.end(); ++it)
		std::cout << *it << " ";
	std::cout << RES << std::endl;

	MutantStack<int>	assigned;
	assigned = original;
	std::cout << GY << "Assigned stack: ";
	for (MutantStack<int>::iterator it = assigned.begin();
		it != assigned.end(); ++it)
		std::cout << *it << " ";
	std::cout << RES << std::endl;

	original.push(999);
	std::cout << GY << "Original after push (copy unaffected): ";
	for (MutantStack<int>::iterator it = copied.begin();
		it != copied.end(); ++it)
		std::cout << *it << " ";
	std::cout << RES << std::endl;
}

static void	testStringStack(void)
{
	std::cout << BY << "\n--- String MutantStack test ---" << RES << std::endl;
	MutantStack<std::string>	sstack;
	sstack.push("Hello");
	sstack.push("World");
	sstack.push("42");
	sstack.push("Barcelona");

	for (MutantStack<std::string>::iterator it = sstack.begin();
		it != sstack.end(); ++it)
		std::cout << BGR << *it << " " << RES;
	std::cout << std::endl;
}

int	main(void)
{
	std::cout << BB << BD << "=== MUTANTSTACK TESTS ===" << RES << std::endl;
	testSubject();
	testSubjectList();
	testReverseIterator();
	testCopyAssign();
	testStringStack();
	std::cout << std::endl;
	return (0);
}
