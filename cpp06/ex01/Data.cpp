#include "Data.hpp"

Data::Data(int integer, double doubleValue, std::string string) : integerValue(integer), doubleValue(doubleValue), stringValue(string)
{
}

Data::~Data()
{
}

Data::Data(const Data &toCopy)
{
	*this = toCopy;
}

Data& Data::operator=(const Data &toCopy)
{
	if (this == &toCopy)
		return (*this);
	integerValue = toCopy.getIntegerValue();
	doubleValue = toCopy.getDoubleValue();
	stringValue = toCopy.getStringValue();
	return (*this);
}

int			Data::getIntegerValue() const
{
	return integerValue;
}

double		Data::getDoubleValue() const
{
	return doubleValue;
}

std::string	Data::getStringValue() const
{
	return stringValue;
}

std::ostream&	operator<<(std::ostream& os, const Data& obj)
{
	os << "integer value = " << obj.getIntegerValue() << ", double value = " << obj.getDoubleValue() << ", string value =  " << obj.getStringValue();
	return os;
}
