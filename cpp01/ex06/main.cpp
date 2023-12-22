#include <iostream>
#include <fstream>
#include <string>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "invalid arguments" << std::endl;
		return (1);
	}
	std::string input = argv[1];
	Harl harl = Harl();
	harl.complain(input);
}
