#ifndef Data_HPP
#define Data_HPP

#include <string>
#include <iostream>

class Data
{
	private:
		int integerValue;
		double doubleValue;
		std::string stringValue;

	public:
		Data(int integer, double doubleValue, std::string string);
		~Data();
		Data(const Data &toCopy);
		Data& operator=(const Data &toCopy);
		int			getIntegerValue() const;
		double		getDoubleValue() const;
		std::string	getStringValue() const;

};

std::ostream&	operator<<(std::ostream& os, const Data& obj);

#endif
