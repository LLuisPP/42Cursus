/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:00:00 by lprieto-          #+#    #+#             */
/*   Updated: 2025/11/10 10:00:00 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &copy)
	: _vec(copy._vec), _deq(copy._deq) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		_vec = copy._vec;
		_deq = copy._deq;
	}
	return (*this);
}

void	PmergeMe::parseInput(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string	arg(argv[i]);
		if (arg.empty())
			throw std::runtime_error("Error");
		for (size_t j = 0; j < arg.length(); j++)
		{
			if (arg[j] < '0' || arg[j] > '9')
				throw std::runtime_error("Error");
		}
		long	num = std::atol(arg.c_str());
		if (num <= 0 || num > 2147483647L)
			throw std::runtime_error("Error");
		_vec.push_back(static_cast<int>(num));
		_deq.push_back(static_cast<int>(num));
	}
	if (_vec.empty())
		throw std::runtime_error("Error");
}

// ─── Jacobsthal sequence generation ─────────────────────────────────────────

std::vector<size_t>	PmergeMe::_getJacobsthalSeq(size_t n)
{
	std::vector<size_t>	seq;

	if (n == 0)
		return (seq);
	seq.push_back(0);
	if (n == 1)
		return (seq);
	seq.push_back(1);
	while (true)
	{
		size_t	next = seq.back() + 2 * seq[seq.size() - 2];
		if (next >= n)
			break ;
		seq.push_back(next);
	}
	return (seq);
}

// ─── Ford-Johnson for std::vector ───────────────────────────────────────────

void	PmergeMe::_binaryInsertVec(std::vector<int> &sorted, int value)
{
	std::vector<int>::iterator pos = std::lower_bound(sorted.begin(),
		sorted.end(), value);
	sorted.insert(pos, value);
}

void	PmergeMe::_sortVector(std::vector<int> &arr)
{
	size_t	size = arr.size();
	if (size <= 1)
		return ;

	// Step 1: Create pairs and determine larger/smaller elements
	std::vector<std::pair<int, int> >	pairs;
	bool	hasStraggler = (size % 2 != 0);
	int		straggler = 0;

	if (hasStraggler)
		straggler = arr.back();

	for (size_t i = 0; i + 1 < size; i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}

	// Step 2: Recursively sort the larger elements
	std::vector<int>	largerElements;
	for (size_t i = 0; i < pairs.size(); i++)
		largerElements.push_back(pairs[i].first);

	_sortVector(largerElements);

	// Step 3: Reorder pairs based on sorted larger elements
	std::vector<int>	pend;
	for (size_t i = 0; i < largerElements.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == largerElements[i])
			{
				pend.push_back(pairs[j].second);
				pairs.erase(pairs.begin() + static_cast<long>(j));
				break ;
			}
		}
	}

	// Step 4: Build the sorted sequence (main chain = sorted larger elements)
	std::vector<int>	sorted = largerElements;

	// Insert first pend element at the beginning (it's always <= first main)
	if (!pend.empty())
		sorted.insert(sorted.begin(), pend[0]);

	// Step 5: Use Jacobsthal sequence for insertion order
	std::vector<size_t>	jacobsthal = _getJacobsthalSeq(pend.size());
	std::vector<bool>	inserted(pend.size(), false);
	inserted[0] = true;

	for (size_t i = 1; i < jacobsthal.size(); i++)
	{
		size_t	jIdx = jacobsthal[i];
		if (jIdx < pend.size() && !inserted[jIdx])
		{
			_binaryInsertVec(sorted, pend[jIdx]);
			inserted[jIdx] = true;
		}
		// Insert elements between current and previous Jacobsthal number
		for (size_t k = jacobsthal[i] - 1; k > jacobsthal[i - 1]; k--)
		{
			if (k < pend.size() && !inserted[k])
			{
				_binaryInsertVec(sorted, pend[k]);
				inserted[k] = true;
			}
		}
	}

	// Insert remaining elements
	for (size_t i = 0; i < pend.size(); i++)
	{
		if (!inserted[i])
			_binaryInsertVec(sorted, pend[i]);
	}

	// Insert straggler if present
	if (hasStraggler)
		_binaryInsertVec(sorted, straggler);

	arr = sorted;
}

// ─── Ford-Johnson for std::deque ────────────────────────────────────────────

void	PmergeMe::_binaryInsertDeq(std::deque<int> &sorted, int value)
{
	std::deque<int>::iterator pos = std::lower_bound(sorted.begin(),
		sorted.end(), value);
	sorted.insert(pos, value);
}

void	PmergeMe::_sortDeque(std::deque<int> &arr)
{
	size_t	size = arr.size();
	if (size <= 1)
		return ;

	// Step 1: Create pairs and determine larger/smaller elements
	std::vector<std::pair<int, int> >	pairs;
	bool	hasStraggler = (size % 2 != 0);
	int		straggler = 0;

	if (hasStraggler)
		straggler = arr.back();

	for (size_t i = 0; i + 1 < size; i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}

	// Step 2: Recursively sort the larger elements
	std::deque<int>	largerElements;
	for (size_t i = 0; i < pairs.size(); i++)
		largerElements.push_back(pairs[i].first);

	_sortDeque(largerElements);

	// Step 3: Reorder pairs based on sorted larger elements
	std::deque<int>	pend;
	for (size_t i = 0; i < largerElements.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == static_cast<int>(largerElements[i]))
			{
				pend.push_back(pairs[j].second);
				pairs.erase(pairs.begin() + static_cast<long>(j));
				break ;
			}
		}
	}

	// Step 4: Build the sorted sequence (main chain = sorted larger elements)
	std::deque<int>	sorted = largerElements;

	// Insert first pend element at the beginning
	if (!pend.empty())
		sorted.insert(sorted.begin(), pend[0]);

	// Step 5: Use Jacobsthal sequence for insertion order
	std::vector<size_t>	jacobsthal = _getJacobsthalSeq(pend.size());
	std::vector<bool>	inserted(pend.size(), false);
	inserted[0] = true;

	for (size_t i = 1; i < jacobsthal.size(); i++)
	{
		size_t	jIdx = jacobsthal[i];
		if (jIdx < pend.size() && !inserted[jIdx])
		{
			_binaryInsertDeq(sorted, pend[jIdx]);
			inserted[jIdx] = true;
		}
		for (size_t k = jacobsthal[i] - 1; k > jacobsthal[i - 1]; k--)
		{
			if (k < pend.size() && !inserted[k])
			{
				_binaryInsertDeq(sorted, pend[k]);
				inserted[k] = true;
			}
		}
	}

	// Insert remaining elements
	for (size_t i = 0; i < pend.size(); i++)
	{
		if (!inserted[i])
			_binaryInsertDeq(sorted, pend[i]);
	}

	// Insert straggler if present
	if (hasStraggler)
		_binaryInsertDeq(sorted, straggler);

	arr = sorted;
}

// ─── Public interface ───────────────────────────────────────────────────────

void	PmergeMe::sort(void)
{
	_sortVector(_vec);
	_sortDeque(_deq);
}

void	PmergeMe::displayResults(double vecTime, double deqTime) const
{
	std::cout << "After:\t";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
		<< " elements with std::deque  : " << deqTime << " us" << std::endl;
}

const std::vector<int>	&PmergeMe::getVector(void) const
{
	return (_vec);
}

const std::deque<int>	&PmergeMe::getDeque(void) const
{
	return (_deq);
}
