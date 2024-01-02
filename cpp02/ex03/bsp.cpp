#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (a == point || b == point || c == point)
		return false;
	//BCP/ABC
	Fixed u = Fixed(((b.getY() - c.getY())*(point.getX() - c.getX()) + (c.getX() - b.getX())*(point.getY() - c.getY())) / ((b.getY() - c.getY())*(a.getX() - c.getX()) + (c.getX() - b.getX())*(a.getY() - c.getY())));
	//ACP/ABC
	Fixed v = Fixed(((c.getY() - a.getY())*(point.getX() - c.getX()) + (a.getX() - c.getX())*(point.getY() - c.getY())) / ((b.getY() - c.getY())*(a.getX() - c.getX()) + (c.getX() - b.getX())*(a.getY() - c.getY())));
	//CAP/ABC
	Fixed w = Fixed(Fixed(1) - u - v);
	if (u == 0 && v >= 0 && w >= 0 && v <= 1 && w <= 1)
		return false;
	if (v == 0 && u >= 0 && w >= 0 && u <= 1 && w <= 1)
		return false;
	if (w == 0 && u >= 0 && v >= 0 && u <= 1 && v <= 1)
		return false;
	if (u >= 0 && v >= 0 && w >= 0 && u <= 1 && v <= 1 && w <= 1)
		return true;
	return false;
}
