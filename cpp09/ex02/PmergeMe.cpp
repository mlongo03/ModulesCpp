#include "PmergeMe.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <set>

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

void	PmergeMe::sort_list()
{
}

std::vector<std::vector<int> > create_pend(std::vector<std::vector<int> > chain, std::vector<std::vector<int> > old_chain, std::vector<int> OddNumber)
{
	std::vector<std::vector<int> > pend;

	// std::cout << "----------\nfrom chain" << std::endl;
	// for (size_t i = 0; i < old_chain.size(); i++)
	// {
	// 	for (size_t j = 0; j < old_chain[i].size(); j++)
	// 		std::cout << old_chain[i][j] << " ";
	// 	std::cout << std::endl;
	// }
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

bool	middle_compare(std::vector<std::vector<int> > &ordered, int number, int start, int end, int &middle)
{
	// std::cout << "end = " << end << ", start = " << start << std::endl;
	if ((end - start) % 2 == 0)
		middle = ((end - start) / 2 - 1) + start;
	else
		middle = ((end - start) / 2) + start;
	// std::cout << "middle = " << middle << std::endl;
	if (number > ordered[middle][0])
		return true;
	else
		return false;
}

void	insert_at(size_t position, std::vector<std::vector<int> > &ordered, std::vector<int> pend_value, size_t front_back)
{
	std::vector<std::vector<int> >::iterator it = ordered.begin();

	// std::cout << "position = " << position << ", " << ((front_back == 1) ? "front" : "back") << std::endl;

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

void	binary_insertion(std::vector<std::vector<int> > pend, std::vector<std::vector<int> > &ordered)
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
		// std::cout << "inserting... " << pend[i][0] << std::endl;
		for (; j_index > jacobsthal[i - 1] - 1; j_index--)
		{
			std::cout << "Jacobstahal index = " << j_index << std::endl;
			start = 0;
			end = ordered.size() - 1;
			while ((end - start) > 0)
			{
				if (middle_compare(ordered, pend[j_index][0], start, end, middle))
					start = middle + 1;
				else
					end = middle - 1;
			}
			if (pend[j_index][0] > ordered[start][0])
				insert_at(start, ordered, pend[j_index], 1);
			else
				insert_at(start, ordered, pend[j_index], -1);
		}
	}
}

void	regenerate_result(std::vector<std::vector<int> > &result, std::vector<std::vector<int> > main_chain)
{
	int ex_pos;

	std::cout << "----------\nbefore result" << std::endl;
	for (size_t i = 0; i < result.size(); i++)
	{
		for (size_t j = 0; j < result[i].size(); j++)
			std::cout << result[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << "----------\nmain chain" << std::endl;
	for (size_t i = 0; i < main_chain.size(); i++)
	{
		for (size_t j = 0; j < main_chain[i].size(); j++)
			std::cout << main_chain[i][j] << " ";
		std::cout << std::endl;
	}
	for (size_t i = 0; i < result.size(); i++)
	{
		ex_pos = result[i][1];
		result[i].clear();
		for (size_t j = 0; j < main_chain[ex_pos].size(); j++)
		{
			if (j % 2 == 0 && main_chain[ex_pos][j] == 0)
				break ;
			result[i].push_back(main_chain[ex_pos][j]);
			std::cout << "--------\ni = " << i << std::endl;
			std::cout << result[i][j] << " = " << main_chain[ex_pos][j] << std::endl;
		}
	}
	std::cout << "----------\nafter result" << std::endl;
	for (size_t i = 0; i < result.size(); i++)
	{
		for (size_t j = 0; j < result[i].size(); j++)
			std::cout << result[i][j] << " ";
		std::cout << std::endl;
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

	// in this for loop i create a vector containing vectors with first number the larger one of the pairs, second its position in the
	// old chain, third the lower number of the array and finally its position in the old chain, i am doing this beacuse every function call
	// aim to order order the largest numbers of the pairs and so every function may can change the position of pairs and so i have to remember
	// where they were before to regain their pending values and insert them in the chain, this is because when i have done with the recursion
	// i am in a situation where i have the main chain ordered and i have to insert pending values in the right order through binary search
	// so coming back to previous function call because recursion is LIFO i have to regenerate pending values from the position of the main chain's
	// values to restore pending values to insert in the current recurtion and so coming back to recursion ensure that the main chain is always
	// ordered and i only have to insert in the right place regained pending values and then return the result to the previous fucntion call. I say
	// regain pending values because i cannot use anymore the current function call pending values because they depend on the order of their
	// corresponding greater values which they may have changed order in later function call and so to regain pending values following the right
	// order i watch the previous order of the larger values and put their pending values to the right order.
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

	// std::cout << "recursion " << recursion << std::endl;
	// std::cout << "----------\nall" << std::endl;
	// for (size_t i = 0; i < main_chain.size(); i++)
	// {
	// 	for (size_t j = 0; j < main_chain[i].size(); j++)
	// 		std::cout << main_chain[i][j] << " ";
	// 	std::cout << std::endl;
	// }

	// std::cout << "main chain" << std::endl;
	// for (size_t i = 0; i < main_chain.size(); i++)
	// 	std::cout << main_chain[i][0] << " ";
	// std::cout << std::endl;

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
		// std::cout << "tmp = " ;
		// for (size_t i = 0; i < tmp.size(); i++)
		// 	std::cout << tmp[i] << " ";
		// std::cout << std::endl;
		return main_chain;
	}
	// std::cout << "recursion " << recursion << std::endl;
	// std::cout << "----------\nresult" << std::endl;
	// for (size_t i = 0; i < result.size(); i++)
	// {
	// 	for (size_t j = 0; j < result[i].size(); j++)
	// 		std::cout << result[i][j] << " ";
	// 	std::cout << std::endl;
	// }

	std::cout << "recursion " << recursion << std::endl;
	pend = create_pend(result, main_chain, OddNumber);
	regenerate_result(result, main_chain);
	std::cout << "----------\npend" << std::endl;
	for (size_t i = 0; i < pend.size(); i++)
	{
		for (size_t j = 0; j < pend[i].size(); j++)
			std::cout << pend[i][j] << " ";
		std::cout << std::endl;
	}

	//make the binary search and insert
	// if (recursion == 1)
	binary_insertion(pend, result);

	return result;
}

void	PmergeMe::sort_vector()
{
	std::vector<std::vector<int> >	first_chain;
	std::vector<std::vector<int> >	result;
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
	result = merge_insertion_vector(first_chain, 0);
	std::cout << "final result" << std::endl;
	for (size_t i = 0; i < result.size(); i++)
	{
		for (size_t j = 0; j < result[i].size(); j++)
			std::cout << result[i][j] << " ";
		std::cout << std::endl;
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

const char* PmergeMe::HasDuplicated::what() const throw()
{
	return "Error: in the given list there are duplcated numbers";
}

std::vector<int>	PmergeMe::get_numbers() const
{
	return numbers;
}
