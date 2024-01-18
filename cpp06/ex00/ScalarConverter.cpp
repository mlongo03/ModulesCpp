#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype>
#include <string>
#include <sstream>

bool ScalarConverter::intOver = false;
bool ScalarConverter::floatOver = false;
bool ScalarConverter::doubleOver = false;

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
	for (std::string::const_iterator it = toConvert.begin(); it != toConvert.end(); ++it)
	{
		if (!isdigit(*it))
		{
			if (!(it == toConvert.begin() && toConvert[0] == '-'))
				return false;
		}
	}
	try
	{
		std::stoi(toConvert);
	}
	catch(const std::exception& e)
	{
		intOver = true;
		return false;
	}

	return true;
}

bool	ScalarConverter::isFloat(const std::string& toConvert)
{
	bool	dot = false;
	int		decimals = 0;
	for (std::string::const_iterator it = toConvert.begin(); *it != 0; ++it)
	{
		if (dot == true)
		{
			for(; *it != 0 ;++it)
			{
				if (!isdigit(*it))
					return false;
				decimals++;
			}
		}
		if (dot == false && !isdigit(*it))
		{
			if (!(it == toConvert.begin() && toConvert[0] == '-'))
			{
				if (*it != '.')
					return false;
				dot = true;
			}
		}
	}
	if (decimals > 7 && dot == true)
		return false;
	try
	{
		std::stof(toConvert);
	}
	catch(const std::exception& e)
	{
		floatOver = true;
		return false;
	}
	return true;
}

bool	ScalarConverter::isDouble(const std::string& toConvert)
{
	bool	dot = false;
	int		decimals = 0;
	for (std::string::const_iterator it = toConvert.begin(); *it != 0; ++it)
	{
		std::cout << *it;
		if (dot == true)
		{
			for(;*it != 0;++it)
			{
				if (!isdigit(*it))
					return false;
				decimals++;
			}
		}
		if (dot == false && !isdigit(*it))
		{
			if (!(it == toConvert.begin() && toConvert[0] == '-'))
			{
				if (*it != '.')
					return false;
				dot = true;
			}
		}
	}
	if (decimals < 8 && dot == true)
		return false;
	try
	{
		std::stod(toConvert);
	}
	catch(const std::exception& e)
	{
		doubleOver = true;
		return false;
	}
	return true;
}

void ScalarConverter::convert(const std::string& toConvert)
{
	if (toConvert == "nan" || toConvert == "nanf" || toConvert == "-nan" || toConvert == "-nanf")
	{
		std::cout << "char -> " <<  "impossible" << std::endl;
		std::cout << "int -> " <<  "impossible" << std::endl;
		std::cout << "float -> " << "nanf" << std::endl;
		std::cout << "double -> " << "nan" << std::endl;
	}
	else if (toConvert == "-inf" || toConvert == "-inff" || toConvert == "inf" || toConvert == "inff")
	{
		std::cout << "char -> " <<  "impossible" << std::endl;
		std::cout << "int -> " <<  "impossible" << std::endl;
		std::cout << "float -> " << toConvert << std::endl;
		std::cout << "double -> " << toConvert << std::endl;
	}
	else if (isInt(toConvert))
	{
		std::cout << " INT " << std::endl;
		int n = std::stoi(toConvert);
		if (static_cast<char>(n) >= 32 && static_cast<char>(n) <= 126)
			std::cout << "char -> " <<  static_cast<char>(n) << std::endl;
		else
			std::cout << "char -> " <<  "not printable" << std::endl;
		std::cout << "int -> " <<  n << std::endl;
		std::cout << "float -> " << static_cast<float>(n) << "f" << std::endl;
		std::cout << "double -> " << static_cast<double>(n) << std::endl;
	}
	else if (isFloat(toConvert))
	{
		std::cout << " FLOAT " << std::endl;
		float n = std::stof(toConvert);
		if (static_cast<char>(n) >= 32 && static_cast<char>(n) <= 126)
			std::cout << "char -> " <<  static_cast<char>(n) << std::endl;
		else
			std::cout << "char -> " <<  "not printable" << std::endl;
		if (intOver)
			std::cout << "int -> " <<  "impossible" << std::endl;
		else
			std::cout << "int -> " << static_cast<int>(n) << std::endl;
		std::cout << "float -> " << n << "f" << std::endl;
		std::cout << "double -> " << static_cast<double>(n) << std::endl;
	}
	else if (isDouble(toConvert))
	{
		std::cout << " DOUBLE " << std::endl;
		double n = std::stod(toConvert);
		if (static_cast<char>(n) >= 32 && static_cast<char>(n) <= 126)
			std::cout << "char -> " <<  static_cast<char>(n) << std::endl;
		else
			std::cout << "char -> " <<  "not printable" << std::endl;
		if (intOver)
			std::cout << "int -> " <<  "impossible" << std::endl;
		else
			std::cout << "int -> " << static_cast<int>(n) << std::endl;
		if (floatOver)
			std::cout << "float -> " <<  "impossible" << std::endl;
		else
			std::cout << "float -> " << static_cast<float>(n) << "f" << std::endl;
		std::cout << "double -> " << n << std::endl;
	}
	else if (!isdigit(toConvert[0]) && toConvert.size() < 2)
	{
		std::cout << " CHAR " << std::endl;
		if (toConvert[0] >= 32 && toConvert[0] <= 126)
			std::cout << "char -> " <<  toConvert[0] << std::endl;
		else
			std::cout << "char -> " <<  "not printable" << std::endl;
		std::cout << "int -> " << static_cast<int>(toConvert[0]) << std::endl;
		std::cout << "float -> " << static_cast<float>(toConvert[0]) << "f" << std::endl;
		std::cout << "double -> " << static_cast<double>(toConvert[0]) << std::endl;
	}
	else if (intOver && floatOver && doubleOver)
	{
		std::cout << "char -> " <<  "impossible" << std::endl;
		std::cout << "int -> " <<  "impossible" << std::endl;
		std::cout << "float -> " << "impossible" << std::endl;
		std::cout << "double -> " << "impossible" << std::endl;
	}
	else
		std::cout << "invalid input" << intOver << floatOver << doubleOver << std::endl;
}
