#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <string>

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
		throw BitcoinExchange::ErrorOpeningFile().what(file);

	if (!file_name.compare(""))
	{
		unordered_exchange_dates.clear();
		unordered_exchange_values.clear();
	}

	file_name = file;

	std::string line;
	getline(inFile, line);

	if (line.find(" | ") == std::string::npos)
		throw BitcoinExchange::WrongSeparator().what(file);

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
		throw BitcoinExchange::ErrorOpeningFile().what(file);

	if (!csv_file_name.compare(""))
		csv.clear();
	csv_file_name = file;

	std::string line;
	getline(inFile, line);

	char separator = findSeparator(line);

	while (getline(inFile, line))
		csv.insert(std::make_pair(line.substr(0, line.find(separator)),  line.substr(line.find(separator) + 1)));
}

void	BitcoinExchange::print_exchange_output()
{
	if (file_name.compare("") || csv_file_name.compare(""))
		throw BitcoinExchange::FileNotLoaded();

	std::deque<std::string>::iterator it_values = unordered_exchange_dates.begin();
	for (std::deque<std::string>::iterator it_dates = unordered_exchange_dates.begin(); it_dates != unordered_exchange_dates.end(); it_dates++)
	{
		if (!analize_date(*it))
			std::cout << "Error: bad input => " << *it << std::endl;
		if (!analize_value(*it))
		
		it_values++;
	}
}

std::multimap<std::string, std::string>	BitcoinExchange::get_csv() const
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

const std::string BitcoinExchange::ErrorOpeningFile::what(std::string file) const throw()
{
	return "Error opening " + file + " file";
}

const std::string BitcoinExchange::WrongSeparator::what(std::string file) const throw()
{
	return "no '|' separator found for exchange file -> " + file;
}

const char* BitcoinExchange::FileNotLoaded::what() const throw()
{
	return "File is not loaded yet";
}
