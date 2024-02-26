#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
	file_name = "";
	csv_file_name = "";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& toCopy)
{
	*this = toCopy;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& toCopy)
{
	if (this == &toCopy)
		return *this;
	this->csv_file_name = toCopy.get_csv_name();
	this->file_name = toCopy.get_file_exchange_name();
	this->csv = toCopy.get_csv();
	this->unordered_exchange_dates = toCopy.unordered_exchange_dates;
	this->unordered_exchange_values = toCopy.unordered_exchange_values;
	return *this;
}

bool isCSVFile(const std::string& filePath)
{
	size_t dotPosition = filePath.find_last_of('.');

	if (dotPosition != std::string::npos && dotPosition < filePath.length() - 1)
	{
		std::string extension = filePath.substr(dotPosition + 1);
		return extension == "csv";
	}
	return false;
}

char	findSeparator(std::string line)
{
	if (line.rfind(',') != std::string::npos)
		return ',';
	else if (line.rfind(';') != std::string::npos)
		return ';';
	else if (line.rfind('\t') != std::string::npos)
		return '\t';
	else if (line.rfind('|') != std::string::npos)
		return '|';
	else
		return ',';
}

void	BitcoinExchange::load_exchange_file(std::string file)
{
	std::ifstream inFile(file.c_str());

	if (!inFile.is_open())
		throw BitcoinExchange::ErrorOpeningFile();

	if (file_name.compare(""))
	{
		unordered_exchange_dates.clear();
		unordered_exchange_values.clear();
	}

	file_name = file;

	std::string line;
	getline(inFile, line);

	if (line.find(" | ") == std::string::npos)
		throw BitcoinExchange::WrongSeparator();

	std::string separator = " | ";

	while (getline(inFile, line))
	{
		if (line.find(separator) == std::string::npos)
		{
			unordered_exchange_dates.push_back(line);
			unordered_exchange_values.push_back("");
		}
		else
		{
			unordered_exchange_dates.push_back(line.substr(0, line.find(separator)));
			unordered_exchange_values.push_back(line.substr(line.find(separator) + 3));
		}
	}
}

void	BitcoinExchange::load_csv_file(std::string file)
{
	if (!isCSVFile(file))
		throw BitcoinExchange::FileIsNotCSV();

	std::ifstream inFile(file.c_str());

	if (!inFile.is_open())
		throw BitcoinExchange::ErrorOpeningFile();

	if (csv_file_name.compare(""))
		csv.clear();
	csv_file_name = file;

	std::string line;
	getline(inFile, line);

	char separator = findSeparator(line);

	float number;

	while (getline(inFile, line))
	{
		std::istringstream iss(line.substr(line.find(separator) + 1));
		iss >> number;
		csv.insert(std::make_pair(line.substr(0, line.find(separator)), number));
	}
}

bool isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool analize_date(const std::string& date)
{
	std::istringstream dateStream(date.c_str());
	int year, month, day;
	char dash1, dash2;

	if (!(dateStream >> year >> dash1 >> month >> dash2 >> day))
		return false;

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31 || dash1 != '-' || dash2 != '-')
		return false;

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	else if (month == 2)
	{
		if (isLeapYear(year))
		{
			if (day > 29)
				return false;
		}
		else
		{
			if (day > 28)
				return false;
		}
	}
	else if (day > 31)
		return false;

	return true;
}

float	analize_value(const std::string& value)
{
	std::istringstream iss(value);
	float number;

	if (!(iss >> number))
		throw BitcoinExchange::InvalidNumber();
	if (number < 0)
		throw BitcoinExchange::NoPositiveNumber();
	if (number > 1000)
		throw BitcoinExchange::TooLargeNumber();
	return number;
}

float	BitcoinExchange::find_value(std::string date, float value)
{
	for (std::multimap<std::string, float>::iterator it = csv.end(); it != csv.begin(); it--)
	{
		if (it == csv.end())
			it--;
		if (date.compare(it->first) >= 0)
			return value * it->second;
	}
	return 0;
}

void	BitcoinExchange::print_exchange_output()
{
	if (!file_name.compare("") || !csv_file_name.compare(""))
		throw BitcoinExchange::FileNotLoaded();

	std::deque<std::string>::iterator it_values = unordered_exchange_values.begin();
	for (std::deque<std::string>::iterator it_dates = unordered_exchange_dates.begin(); it_dates != unordered_exchange_dates.end(); it_dates++)
	{
		if (!analize_date(*it_dates))
			std::cout << "Error: bad input => " << *it_dates << std::endl;
		else
		{
			try
			{
				float number = analize_value(*it_values);
				std::cout << *it_dates << " => " << *it_values << " = " << find_value(*it_dates, number) << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}

		it_values++;
	}
}

std::multimap<std::string, float>	BitcoinExchange::get_csv() const
{
	return this->csv;
}

std::deque<std::string>	BitcoinExchange::get_unordered_dates() const
{
	return unordered_exchange_dates;
}

std::deque<std::string>	BitcoinExchange::get_unordered_values() const
{
	return unordered_exchange_values;
}

std::string	BitcoinExchange::get_file_exchange_name() const
{
	return this->file_name;
}

std::string	BitcoinExchange::get_csv_name() const
{
	return this->csv_file_name;
}

const char* BitcoinExchange::FileIsNotCSV::what() const throw()
{
	return "File is not a CSV file";
}

const char* BitcoinExchange::ErrorOpeningFile::what() const throw()
{
	return "Error opening file";
}

const char* BitcoinExchange::WrongSeparator::what() const throw()
{
	return "no '|' separator found for exchange file or is empty";
}

const char* BitcoinExchange::FileNotLoaded::what() const throw()
{
	return "File is not loaded yet";
}

const char* BitcoinExchange::InvalidNumber::what() const throw()
{
	return "Error: invalid number";
}

const char* BitcoinExchange::NoPositiveNumber::what() const throw()
{
	return "Error: not a positive number.";
}

const char* BitcoinExchange::TooLargeNumber::what() const throw()
{
	return "Error: too large a number.";
}
