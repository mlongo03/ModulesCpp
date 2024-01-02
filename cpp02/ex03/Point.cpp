#include <iostream>
#include <string>
#include <cmath>
#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0))
{
}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y)
{
}

Point::Point(const Point &toCopy) : x(toCopy.x), y(toCopy.y)
{
}

Point::~Point()
{
}

Point&	Point::operator=(const Point &toCopy)
{
	(void)toCopy;
	return (*this);
}

bool	Point::operator==(const Point &obj) const
{
	if (this->getX() == obj.getX() && this->getY() == obj.getY())
		return true;
	return false;
}

Fixed	Point::getX() const
{
	return (this->x);
}

Fixed	Point::getY() const
{
	return (this->y);
}
