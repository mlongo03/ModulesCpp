#include "PmergeMe.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <set>
#include <ctime>

size_t jacobsthal[] = {
    1u, 3u, 5u, 11u, 21u, 43u, 85u, 171u, 341u, 683u, 1365u,
    2731u, 5461u, 10923u, 21845u, 43691u, 87381u, 174763u, 349525u, 699051u,
    1398101u, 2796203u, 5592405u, 11184811u, 22369621u, 44739243u, 89478485u,
    178956971u, 357913941u, 715827883u, 1431655765u,
    2863311531u, 5726623061u, 11453246123u
};

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

bool	middle_compare_deque(std::deque<std::deque<int> > &ordered, int number, int start, int end, int &middle)
{
	if ((end - start) % 2 == 0)
		middle = ((end - start) / 2 - 1) + start;
	else
		middle = ((end - start) / 2) + start;
	if (number > ordered[middle][0])
		return true;
	else
		return false;
}

void	insert_at_deque(size_t position, std::deque<std::deque<int> > &ordered, std::deque<int> pend_value, size_t front_back)
{
	std::deque<std::deque<int> >::iterator it = ordered.begin();

	if (position + front_back == ordered.size())
		ordered.push_back(pend_value);
	else if (position + front_back == (size_t)-1)
		ordered.push_front(pend_value);
	else
	{
		if (front_back == 1)
			position++;
		for (size_t i = 0; i < position; i++)
			it++;
		ordered.insert(it, pend_value);
	}
}

void	binary_insertion_deque(std::deque<std::deque<int> > pend, std::deque<std::deque<int> > &ordered)
{
	int start;
	int end;
	int middle = 0;
	size_t j_index;

	if (pend.size() == 0)
		return ;
	ordered.push_front(pend[0]);
	for (size_t i = 1; jacobsthal[i]; i++)
	{
		if (jacobsthal[i] > pend.size())
		{
			if (jacobsthal[i - 1] >= pend.size())
				return ;
			j_index = pend.size() - 1;
		}
		else
			j_index = jacobsthal[i] - 1;
		for (; j_index > jacobsthal[i - 1] - 1; j_index--)
		{
			start = 0;
			end = ordered.size() - 1;
			while ((end - start) > 0)
			{
				if (middle_compare_deque(ordered, pend[j_index][0], start, end, middle))
					start = middle + 1;
				else
					end = middle - 1;
			}
			if (pend[j_index][0] > ordered[start][0])
				insert_at_deque(start, ordered, pend[j_index], 1);
			else
				insert_at_deque(start, ordered, pend[j_index], -1);
		}
	}
}

void	regenerate_result_deque(std::deque<std::deque<int> > &result, std::deque<std::deque<int> > main_chain)
{
	int ex_pos;

	for (size_t i = 0; i < result.size(); i++)
	{
		ex_pos = result[i][1];
		result[i].clear();
		for (size_t j = 0; j < main_chain[ex_pos].size(); j++)
		{
			if (j % 2 == 0 && main_chain[ex_pos][j] == 0)
				break ;
			result[i].push_back(main_chain[ex_pos][j]);
		}
	}
}

std::deque<std::deque<int> > create_pend_deque(std::deque<std::deque<int> > chain, std::deque<std::deque<int> > old_chain, std::deque<int> OddNumber)
{
	std::deque<std::deque<int> > pend;

	for (size_t i = 0; i < chain.size(); i++)
	{
		std::deque<int> tmp;
		tmp.push_back(old_chain[chain[i][1]][2]);
		tmp.push_back(old_chain[chain[i][1]][3]);
		pend.push_back(tmp);
	}
	if (OddNumber[0] != -1)
		pend.push_back(OddNumber);

	return pend;
}

std::deque<std::deque<int> > merge_insertion_deque(std::deque<std::deque<int> > input_chain, int recursion)
{
	std::deque<std::deque<int> > main_chain;
	std::deque<std::deque<int> > result;
	std::deque<std::deque<int> > pend;
	std::deque<int> OddNumber;

	OddNumber.push_back(-1);
	if (input_chain.size() % 2 != 0)
	{
		OddNumber = input_chain.back();
		OddNumber[1] = input_chain.size() - 1;
		input_chain.pop_back();
	}

	for (size_t i = 0; i < input_chain.size(); i += 2)
	{
		if (input_chain[i][0] > input_chain[i + 1][0])
		{
			std::deque<int>	tmp;
			tmp.push_back(input_chain[i][0]);
			tmp.push_back(i);
			main_chain.push_back(tmp);
			main_chain.back().push_back(input_chain[i + 1][0]);
			main_chain.back().push_back(i + 1);
		}
		else
		{
			std::deque<int>	tmp;
			tmp.push_back(input_chain[i + 1][0]);
			tmp.push_back(i + 1);
			main_chain.push_back(tmp);
			main_chain.back().push_back(input_chain[i][0]);
			main_chain.back().push_back(i);
		}
	}

	if (main_chain.size() != 1)
		result = merge_insertion_deque(main_chain, recursion + 1);
	else
	{
		std::deque<std::deque<int> >::iterator it;
		it = main_chain.begin();
		std::deque<int>	tmp;
		tmp.push_back(main_chain[0][main_chain[0].size() - 2]);
		tmp.push_back(main_chain[0][main_chain[0].size() - 1]);
		main_chain.push_front(tmp);
		if (OddNumber[0] != -1)
		{
			if (OddNumber[0] < main_chain[0][0])
				main_chain.push_front(OddNumber);
			else if (OddNumber[0] < main_chain[1][0])
				main_chain.insert (it + 1 , OddNumber);
			else
				main_chain.push_back(OddNumber);

		}
		return main_chain;
	}

	pend = create_pend_deque(result, main_chain, OddNumber);
	regenerate_result_deque(result, main_chain);
	binary_insertion_deque(pend, result);

	return result;
}

void	PmergeMe::sort_deque()
{
	std::deque<std::deque<int> >	first_chain;
	std::deque<std::deque<int> >	result;
	std::deque<int>				tmp;

    clock_t start = clock();

	std::cout << RED << "unsorted deque = ";
	for (size_t i = 0; i < numbers.size(); i++)
	{
		std::cout << RED << numbers[i] << " ";
		tmp.push_back(numbers[i]);
		first_chain.push_back(tmp);
		tmp.clear();
	}
	std::cout << RESET << std::endl;

	result = merge_insertion_deque(first_chain, 0);

    clock_t end = clock();
	std::cout << GREEN << "sorted deque   = ";
	for (size_t i = 0; i < result.size(); i++)
		std::cout << GREEN << result[i][0] << " ";
	std::cout << RESET << std::endl;
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    std::cout << BLUE << "Time needed by deque to sort: " << WHITE << elapsed_time << " seconds" << RESET << std::endl;
}

std::vector<std::vector<int> > create_pend_vector(std::vector<std::vector<int> > chain, std::vector<std::vector<int> > old_chain, std::vector<int> OddNumber)
{
	std::vector<std::vector<int> > pend;

	for (size_t i = 0; i < chain.size(); i++)
	{
		std::vector<int> tmp;
		tmp.push_back(old_chain[chain[i][1]][2]);
		tmp.push_back(old_chain[chain[i][1]][3]);
		pend.push_back(tmp);
	}
	if (OddNumber[0] != -1)
		pend.push_back(OddNumber);

	return pend;
}

bool	middle_compare_vector(std::vector<std::vector<int> > &ordered, int number, int start, int end, int &middle)
{
	if ((end - start) % 2 == 0)
		middle = ((end - start) / 2 - 1) + start;
	else
		middle = ((end - start) / 2) + start;
	if (number > ordered[middle][0])
		return true;
	else
		return false;
}

void	insert_at_vector(size_t position, std::vector<std::vector<int> > &ordered, std::vector<int> pend_value, size_t front_back)
{
	std::vector<std::vector<int> >::iterator it = ordered.begin();

	if (position + front_back == ordered.size())
		ordered.push_back(pend_value);
	else if (position + front_back == (size_t)-1)
		ordered.insert(it, pend_value);
	else
	{
		if (front_back == 1)
			position++;
		for (size_t i = 0; i < position; i++)
			it++;
		ordered.insert(it, pend_value);
	}
}

void	binary_insertion_vector(std::vector<std::vector<int> > pend, std::vector<std::vector<int> > &ordered)
{
	std::vector<std::vector<int> >::iterator it = ordered.begin();
	int start;
	int end;
	int middle = 0;
	size_t j_index;

	if (pend.size() == 0)
		return ;
	ordered.insert(it, pend[0]);
	for (size_t i = 1; jacobsthal[i]; i++)
	{
		if (jacobsthal[i] > pend.size())
		{
			if (jacobsthal[i - 1] >= pend.size())
				return ;
			j_index = pend.size() - 1;
		}
		else
			j_index = jacobsthal[i] - 1;
		for (; j_index > jacobsthal[i - 1] - 1; j_index--)
		{
			start = 0;
			end = ordered.size() - 1;
			while ((end - start) > 0)
			{
				if (middle_compare_vector(ordered, pend[j_index][0], start, end, middle))
					start = middle + 1;
				else
					end = middle - 1;
			}
			if (pend[j_index][0] > ordered[start][0])
				insert_at_vector(start, ordered, pend[j_index], 1);
			else
				insert_at_vector(start, ordered, pend[j_index], -1);
		}
	}
}

void	regenerate_result_vector(std::vector<std::vector<int> > &result, std::vector<std::vector<int> > main_chain)
{
	int ex_pos;

	for (size_t i = 0; i < result.size(); i++)
	{
		ex_pos = result[i][1];
		result[i].clear();
		for (size_t j = 0; j < main_chain[ex_pos].size(); j++)
		{
			if (j % 2 == 0 && main_chain[ex_pos][j] == 0)
				break ;
			result[i].push_back(main_chain[ex_pos][j]);
		}
	}
}

std::vector<std::vector<int> > merge_insertion_vector(std::vector<std::vector<int> > input_chain, int recursion)
{
	std::vector<std::vector<int> > main_chain;
	std::vector<std::vector<int> > result;
	std::vector<std::vector<int> > pend;
	std::vector<int> OddNumber;

	OddNumber.push_back(-1);
	if (input_chain.size() % 2 != 0)
	{
		OddNumber = input_chain.back();
		OddNumber[1] = input_chain.size() - 1;
		input_chain.pop_back();
	}

	for (size_t i = 0; i < input_chain.size(); i += 2)
	{
		if (input_chain[i][0] > input_chain[i + 1][0])
		{
			std::vector<int>	tmp;
			tmp.push_back(input_chain[i][0]);
			tmp.push_back(i);
			main_chain.push_back(tmp);
			main_chain.back().push_back(input_chain[i + 1][0]);
			main_chain.back().push_back(i + 1);
		}
		else
		{
			std::vector<int>	tmp;
			tmp.push_back(input_chain[i + 1][0]);
			tmp.push_back(i + 1);
			main_chain.push_back(tmp);
			main_chain.back().push_back(input_chain[i][0]);
			main_chain.back().push_back(i);
		}
	}

	if (main_chain.size() != 1)
		result = merge_insertion_vector(main_chain, recursion + 1);
	else
	{
		std::vector<std::vector<int> >::iterator it;
		it = main_chain.begin();
		std::vector<int>	tmp;
		tmp.push_back(main_chain[0][main_chain[0].size() - 2]);
		tmp.push_back(main_chain[0][main_chain[0].size() - 1]);
		it = main_chain.insert (it , tmp);
		if (OddNumber[0] != -1)
		{
			if (OddNumber[0] < main_chain[0][0])
				main_chain.insert (it , OddNumber);
			else if (OddNumber[0] < main_chain[1][0])
				main_chain.insert (it + 1 , OddNumber);
			else
				main_chain.push_back(OddNumber);

		}
		return main_chain;
	}

	pend = create_pend_vector(result, main_chain, OddNumber);
	regenerate_result_vector(result, main_chain);
	binary_insertion_vector(pend, result);

	return result;
}

void	PmergeMe::sort_vector()
{
	std::vector<std::vector<int> >	first_chain;
	std::vector<std::vector<int> >	result;
	std::vector<int>				tmp;

	clock_t start = clock();

	std::cout << RED << "unsorted vector = ";
	for (size_t i = 0; i < numbers.size(); i++)
	{
		std::cout << RED << numbers[i] << " ";
		tmp.push_back(numbers[i]);
		first_chain.push_back(tmp);
		tmp.clear();
	}
	std::cout << RESET << std::endl;
	result = merge_insertion_vector(first_chain, 0);
    clock_t end = clock();
	std::cout << GREEN << "sorted vector   = ";
	for (size_t i = 0; i < result.size(); i++)
		std::cout << GREEN << result[i][0] << " ";
	std::cout << RESET << std::endl;
	double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
	std::cout << BLUE << "Time needed by vector to sort: " << WHITE << elapsed_time << " seconds" << RESET << std::endl;

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
