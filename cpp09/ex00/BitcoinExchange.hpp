#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <map>
#include <list>
#include <iostream>

class BitcoinExchange
{
	private:
		std::string file_name;
		std::string csv_file_name;
		std::multimap<std::string, float> csv;
		std::list<std::string> unordered_exchange_values;
		std::list<std::string>	unordered_exchange_dates;
		float	find_value(std::string date, float value);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& toCopy);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& toCopy);
		void								load_exchange_file(std::string file);
		void								load_csv_file(std::string file);
		void								print_exchange_output();
		std::multimap<std::string, float>	get_csv() const;
		std::list<std::string>				get_unordered_dates() const;
		std::list<std::string>				get_unordered_values() const;
		std::string							get_file_exchange_name() const;
		std::string							get_csv_name() const;
	public:
		class FileIsNotCSV : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class ErrorOpeningFile : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class WrongSeparator : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class FileNotLoaded : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NoPositiveNumber : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class TooLargeNumber : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InvalidNumber : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
