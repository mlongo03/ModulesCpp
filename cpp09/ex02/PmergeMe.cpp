#include "PmergeMe.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

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
	this->stack_list = toCopy.get_list();
	this->stack_vector = toCopy.get_vector();
	return *this;
}

void	check_arguments(char **argv)
{
	std::string string;
	int number;

	for (int i = 0; argv[i]; i++)
	{
		std::istringstream iss(argv[i]);
		if (!(iss >> number))
			throw PmergeMe::NotAnInteger();
		else if (number < 0)
			throw PmergeMe::NegativeNumber();
	}
}

void	PmergeMe::load_vector(char **argv)
{
	std::string string;
	int number;

	for (int i = 0; argv[i]; i++)
	{
		std::istringstream iss(argv[i]);
		iss >> number;
		this->stack_vector.push_back(number);
	}

}

void	PmergeMe::load_list(char **argv)
{
	std::string string;
	int number;

	for (int i = 0; argv[i]; i++)
	{
		std::istringstream iss(argv[i]);
		iss >> number;
		this->stack_list.push_back(number);
	}
}

const char* PmergeMe::NotAnInteger::what() const throw()
{
	return "Error: in the given list there are elements that are not integers";
}

const char* PmergeMe::NegativeNumber::what() const throw()
{
	return "Error: in the given list there are negative numbers";
}

std::list<int>	PmergeMe::get_list() const
{
	return stack_list;
}

std::vector<int>	PmergeMe::get_vector() const
{
	return stack_vector;
}
