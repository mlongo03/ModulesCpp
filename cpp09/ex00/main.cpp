#include "BitcoinExchange.hpp"
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

	BitcoinExchange btc;

	try
	{
		btc.load_csv_file("./data.csv");
		btc.load_exchange_file((std::string)argv[1]);
		btc.print_exchange_output();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
