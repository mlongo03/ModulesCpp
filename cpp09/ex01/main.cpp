#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: usage <program name> <inverted Polish mathematical expression>" << std::endl;
		return 1;
	}

	RPN rpn;
	rpn.calculate_RPN(argv[1]);

	return 0;
}
