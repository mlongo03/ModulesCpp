#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <map>
#include <iostream>

class BitcoinExchange
{
	private:
		std::string file_name;
		std::string csv_file_name;
		std::map<std::string, float> csv;
		std::map<std::string, float> file_exchange;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& toCopy);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& toCopy);
		void	load_exchange_file(std::string file);
		void	load_csv_file(std::string file);
		void	print_exchange_output();
};

#endif
