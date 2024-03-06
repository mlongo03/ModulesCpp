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
	this->stack_list = toCopy.get_list();
	this->stack_vector = toCopy.get_vector();
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

void	PmergeMe::sort_list()
{

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

std::list<int>	PmergeMe::get_list() const
{
	return stack_list;
}

std::vector<int>	PmergeMe::get_vector() const
{
	return stack_vector;
}
