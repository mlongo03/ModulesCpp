#include "PmergeMe.hpp"
#include <vector>
#include <list>

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cout << "Error: usage <program name> list of positive integer numbers" << std::endl;
		return 1;
	}

	PmergeMe algorithm;

	try
	{
		algorithm.load_numbers(&argv[1]);
		algorithm.sort_deque();
		algorithm.sort_vector();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}


	return 0;
}
