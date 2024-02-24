#include "easyfind.hpp"
#include <vector>
#include <list>

int main(int argc, char **argv)
{
	if (argc > 2)
	{
		std::cout << "Error: too many arguments" << std::endl;
		return 1;
	}
	if (argc < 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	

	return 0;
}
