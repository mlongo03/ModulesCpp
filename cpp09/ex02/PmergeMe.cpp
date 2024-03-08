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
	std::list<int> main_chain;
	std::list<int> second_chain;
	int OddNumber = -1;

	if (numbers.size() % 2 != 0)
	{
		OddNumber = numbers.back();
		numbers.pop_back();
	}

	for (size_t i = 0; i < numbers.size(); i += 2)
	{
		if (numbers[i] > numbers[i + 1])
		{
			main_chain.push_back(numbers[i]);
			second_chain.push_back(numbers[i + 1]);
		}
		else
		{
			main_chain.push_back(numbers[i + 1]);
			second_chain.push_back(numbers[i]);
		}
	}

	if (OddNumber >= 0)
		second_chain.push_back(OddNumber);

	std::cout << "original list" << std::endl;
	for (size_t i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;
	std::cout << "main chain" << std::endl;
	for (std::list<int>::iterator it = main_chain.begin(); it != main_chain.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "second chain" << std::endl;
	for (std::list<int>::iterator it = second_chain.begin(); it != second_chain.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::sort_vector()
{

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
