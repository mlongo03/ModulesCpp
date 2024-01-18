#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <string>
#include <iostream>

class ScalarConverter
{
	private:

	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &toCopy);
		ScalarConverter& operator=(const ScalarConverter &toCopy);
		static void	convert(const std::string& toConvert);
		static bool	isInt(const std::string& toConvert);
		static bool	isFloat(const std::string& toConvert);
		static bool	isDouble(const std::string& toConvert);
};

#endif
