#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype>
#include <string>
#include <sstream>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &toCopy)
{
	*this = toCopy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &toCopy)
{
	if (this == &toCopy)
		return (*this);
	return (*this);
}

bool	ScalarConverter::isInt(const std::string& toConvert)
{
	if (toConvert.empty())
		return false;

	for (std::string::const_iterator it = toConvert.begin(); it != toConvert.end(); ++it)
	{
		if (!isdigit(*it))
			return false;
	}
	return true;
}

bool	ScalarConverter::isFloat(const std::string& toConvert)
{
	bool	dot = false;
	int		decimals = 0;
	if (toConvert.empty())
		return false;
	for (std::string::const_iterator it = toConvert.begin(); it != toConvert.end(); ++it)
	{
		if (dot == true)
		{
			for(;it != toConvert.end();++it)
			{
				if (!isdigit(*it))
					return false;
				decimals++;
			}
		}
		if (dot == false && !isdigit(*it))
		{
			if (*it != '.')
				return false;
			dot = true;
		}
	}
	if (decimals > 7)
		return false;
	return true;
}

bool	ScalarConverter::isDouble(const std::string& toConvert)
{
	bool	dot = false;
	int		decimals = 0;
	if (toConvert.empty())
		return false;
	for (std::string::const_iterator it = toConvert.begin(); it != toConvert.end(); ++it)
	{
		if (dot == true)
		{
			for(;it != toConvert.end();++it)
			{
				if (!isdigit(*it))
					return false;
				decimals++;
			}
		}
		if (dot == false && !isdigit(*it))
		{
			if (*it != '.')
				return false;
			dot = true;
		}
	}
	if (decimals < 8)
		return false;
	return true;
}

void ScalarConverter::convert(const std::string& toConvert)
{
	if (isInt(toConvert))
	{
		std::cout << " INT " << std::endl;
		int n = std::stoi(toConvert);
		std::cout << "char -> " <<  static_cast<char>(n) << std::endl;
		std::cout << "int -> " <<  n << std::endl;
		std::cout << "float -> " << static_cast<float>(n) << "f" << std::endl;
		std::cout << "double -> " << static_cast<double>(n) << std::endl;
	}
}
