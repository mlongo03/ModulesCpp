#include "PmergeMe.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <set>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& toCopy)
{
	*this = toCopy;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& toCopy)
{
	if (this == &toCopy)
		return *this;
	this->numbers = toCopy.get_numbers();
	return *this;
}

void	PmergeMe::check_arguments(char **argv)
{
	std::set<int> uniqueStrings;
	std::string string;
	int number;

	for (int i = 0; argv[i]; i++)
	{
		std::istringstream iss(argv[i]);
		if (!(iss >> number))
			throw PmergeMe::NotAnInteger();
		else if (number < 0)
			throw PmergeMe::NegativeNumber();
		else if (!uniqueStrings.insert(number).second)
			throw PmergeMe::HasDuplicated();
	}
}

void	PmergeMe::load_numbers(char **argv)
{
	check_arguments(argv);
	std::string string;
	int number;

	for (int i = 0; argv[i]; i++)
	{
		std::istringstream iss(argv[i]);
		iss >> number;
		this->numbers.push_back(number);
	}
}

void	PmergeMe::sort_list()
{
}

std::vector<int> create_pend(std::vector<std::vector<int> > chain, int OddNumber, int recursion_depth)
{
	std::vector<int> pend;

	// std::cout << "\nrecursion depth = " << recursion_depth << std::endl;
	for (size_t i = 0; i < chain.size(); i++)
		pend.push_back(chain[i][recursion_depth + 1]);
	if (OddNumber != -1)
		pend.push_back(OddNumber);

	return pend;
}

std::vector<std::vector<int> > merge_insertion_vector(std::vector<std::vector<int> > input_chain, int recursion_depth)
{
	std::vector<std::vector<int> > main_chain;
	std::vector<std::vector<int> > result;
	std::vector<int> pend;

	int OddNumber = -1;

	if (input_chain.size() % 2 != 0)
	{
		OddNumber = input_chain.back()[0];
		input_chain.pop_back();
	}

	(void)OddNumber;

	for (size_t i = 0; i < input_chain.size(); i += 2)
	{
		// std::cout << input_chain[i][0] << " > " << input_chain[i + 1][0] << std::endl;
		if (input_chain[i][0] > input_chain[i + 1][0])
		{
			main_chain.push_back(input_chain[i]);
			main_chain.back().push_back(input_chain[i + 1][0]);
			main_chain.back().push_back(i + 1);
			// input_chain[i].push_back(input_chain[i + 1][0]);
		}
		else
		{
			main_chain.push_back(input_chain[i + 1]);
			main_chain.back().push_back(input_chain[i][0]);
			main_chain.back().push_back(i);
			// input_chain[i + 1].push_back(input_chain[i][0]);
			// main_chain.push_back(input_chain[i + 1]);
		}
	}

	std::cout << "all" << std::endl;
	for (size_t i = 0; i < main_chain.size(); i++)
	{
		for (size_t j = 0; j < main_chain[i].size(); j++)
			std::cout << main_chain[i][j] << " ";
		std::cout << std::endl;
	}

	// std::cout << "main chain" << std::endl;
	// for (size_t i = 0; i < main_chain.size(); i++)
	// 	std::cout << main_chain[i][0] << " ";
	// std::cout << std::endl;

	if (input_chain.size() != 2)
		result = merge_insertion_vector(main_chain, recursion_depth + 1);
	else
	{
		std::vector<std::vector<int> >::iterator it;
		it = main_chain.begin();
		std::vector<int>	tmp;
		tmp.push_back(main_chain[0][main_chain[0].size() - 2]);
		tmp.push_back(main_chain[0][main_chain[0].size() - 1]);
		it = main_chain.insert (it , input_chain[1]);
		return main_chain;
	}

	// pend = create_pend(result, OddNumber, recursion_depth);
	// std::cout << "result -> ";
	// for (size_t i = 0; i < result.size(); i++)
	// 	std::cout << result[i][0] << " ";
	// std::cout << std::endl;
	std::cout << "result" << std::endl;
	for (size_t i = 0; i < result.size(); i++)
	{
		for (size_t j = 0; j < result[i].size(); j++)
			std::cout << result[i][j] << " ";
		std::cout << std::endl;
	}

	// for (size_t i = 0; i < pend.size(); i++)
	// 	std::cout << pend[i] << " ";
	// std::cout << std::endl;

	return main_chain;
}

void	PmergeMe::sort_vector()
{
	std::vector<std::vector<int> >	first_chain;
	std::vector<int>				tmp;

	for (size_t i = 0; i < numbers.size(); i++)
	{
		tmp.push_back(numbers[i]);
		first_chain.push_back(tmp);
		tmp.clear();
	}
	std::cout << "first chain" << std::endl;
	for (size_t i = 0; i < first_chain.size(); i++)
		std::cout << first_chain[i][0] << " ";
	std::cout << std::endl;
	merge_insertion_vector(first_chain, 0);
}

const char* PmergeMe::NotAnInteger::what() const throw()
{
	return "Error: in the given list there are elements that are not integers";
}

const char* PmergeMe::NegativeNumber::what() const throw()
{
	return "Error: in the given list there are negative numbers";
}

const char* PmergeMe::HasDuplicated::what() const throw()
{
	return "Error: in the given list there are duplcated numbers";
}

std::vector<int>	PmergeMe::get_numbers() const
{
	return numbers;
}
