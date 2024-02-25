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

	// btc.load_csv_file("./data.csv");
	btc.load_exchange_file((std::string)argv[1]);

	// std::multimap<std::string, std::string> csv = btc.get_csv();
	std::multimap<std::string, std::string> exchange_multimap = btc.get_file_exchange();

	// for (std::multimap<std::string, std::string>::iterator it = csv.begin(); it != csv.end(); it++)
	// 	std::cout << it->first << " " << it->second << std::endl;

	// std::cout << "----------------------------------------------------" << std::endl;

	for (std::multimap<std::string, std::string>::iterator it = exchange_multimap.begin(); it != exchange_multimap.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;

	return 0;
}
