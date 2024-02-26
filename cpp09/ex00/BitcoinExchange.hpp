#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <map>
#include <deque>
#include <iostream>

class BitcoinExchange
{
	private:
		std::string file_name;
		std::string csv_file_name;
		std::multimap<std::string, std::string> csv;
		std::deque<std::string> unordered_exchange_values;
		std::deque<std::string>	unordered_exchange_dates;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& toCopy);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& toCopy);
		void									load_exchange_file(std::string file);
		void									load_csv_file(std::string file);
		void									print_exchange_output();
		std::multimap<std::string, std::string>	get_csv() const;
		std::deque<std::string>					get_unordered_dates() const;
		std::deque<std::string>					get_unordered_values() const;
		std::string								get_file_exchange_name() const;
		std::string								get_csv_name() const;
	public:
		class FileIsNotCSV : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class ErrorOpeningFile : public std::exception
		{
			public:
				virtual const std::string what(std::string file) const throw();
		};
		class WrongSeparator : public std::exception
		{
			public:
				virtual const std::string what(std::string file) const throw();
		};
		class FileNotLoaded : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
