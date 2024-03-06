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
		algorithm.check_arguments(&argv[1]);
		algorithm.load_list(&argv[1]);
		algorithm.load_vector(&argv[1]);
		algorithm.sort_list();
		algorithm.sort_vector();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return 0;
}
