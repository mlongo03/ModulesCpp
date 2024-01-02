#ifndef Point_HPP
#define Point_HPP
#include "Fixed.hpp"

#include <string>

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(const Fixed x, const Fixed y);
	Point(const Point& toCopy);
	~Point();
	Point&	operator=(const Point &toCopy);
	bool	operator==(const Point &obj) const;
	Fixed	getX() const;
	Fixed	getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
