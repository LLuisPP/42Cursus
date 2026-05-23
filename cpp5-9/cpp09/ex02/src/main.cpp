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

		// Sort and time vector
		PmergeMe	vecSorter;
		vecSorter.parseInput(argc, argv);
		clock_t	startVec = clock();
		vecSorter.sort();
		clock_t	endVec = clock();
		double	vecTime = static_cast<double>(endVec - startVec)
			/ CLOCKS_PER_SEC * 1000000.0;

		// Sort and time deque
		PmergeMe	deqSorter;
		deqSorter.parseInput(argc, argv);
		clock_t	startDeq = clock();
		deqSorter.sort();
		clock_t	endDeq = clock();
		double	deqTime = static_cast<double>(endDeq - startDeq)
			/ CLOCKS_PER_SEC * 1000000.0;

		// Use vecSorter for display (it's already sorted)
		sorter.sort();

		sorter.displayResults(vecTime, deqTime);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
