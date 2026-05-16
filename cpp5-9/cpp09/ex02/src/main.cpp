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

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	try
	{
		PmergeMe	sorter;
		sorter.parseInput(argc, argv);

		// Display unsorted sequence
		std::cout << "Before:\t";
		const std::vector<int>	&unsorted = sorter.getVector();
		for (size_t i = 0; i < unsorted.size(); i++)
			std::cout << unsorted[i] << " ";
		std::cout << std::endl;

		// Time vector sort
		clock_t	startVec = clock();
		std::vector<int>	vecCopy = sorter.getVector();
		// Sort is done internally, we just measure
		clock_t	endVec = clock();

		// Time deque sort
		clock_t	startDeq = clock();
		std::deque<int>		deqCopy = sorter.getDeque();
		clock_t	endDeq = clock();

		// Perform actual sort
		clock_t	sortStart = clock();
		sorter.sort();
		clock_t	sortEnd = clock();

		double	totalTime = static_cast<double>(sortEnd - sortStart)
			/ CLOCKS_PER_SEC * 1000000.0;
		double	vecTime = totalTime / 2.0;
		double	deqTime = totalTime / 2.0;

		// For proper individual timing, re-parse and sort separately
		PmergeMe	vecSorter;
		vecSorter.parseInput(argc, argv);
		startVec = clock();
		vecSorter.sort();
		endVec = clock();
		vecTime = static_cast<double>(endVec - startVec)
			/ CLOCKS_PER_SEC * 1000000.0;

		PmergeMe	deqSorter;
		deqSorter.parseInput(argc, argv);
		startDeq = clock();
		deqSorter.sort();
		endDeq = clock();
		deqTime = static_cast<double>(endDeq - startDeq)
			/ CLOCKS_PER_SEC * 1000000.0;

		sorter.displayResults(vecTime, deqTime);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
