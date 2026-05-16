/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:00:00 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/10 10:00:00 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

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
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <algorithm>
#include <utility>

class PmergeMe {

	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		// Jacobsthal number generation
		static std::vector<size_t>	_getJacobsthalSeq(size_t n);

		// Ford-Johnson for vector
		void	_sortVector(std::vector<int> &arr);
		void	_binaryInsertVec(std::vector<int> &sorted, int value);

		// Ford-Johnson for deque
		void	_sortDeque(std::deque<int> &arr);
		void	_binaryInsertDeq(std::deque<int> &sorted, int value);

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &copy);
		~PmergeMe(void);

		PmergeMe &operator=(const PmergeMe &copy);

		void	parseInput(int argc, char **argv);
		void	sort(void);
		void	displayResults(double vecTime, double deqTime) const;

		const std::vector<int>	&getVector(void) const;
		const std::deque<int>	&getDeque(void) const;
};

#endif
