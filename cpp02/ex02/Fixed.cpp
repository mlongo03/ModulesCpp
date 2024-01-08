#include <iostream>
#include <string>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::fractBits = 8;

Fixed::Fixed()
{
	fpn = 0;
}

Fixed::Fixed(const Fixed &toCopy)
{
	*this = toCopy;
	return;
}

Fixed::Fixed(const int num)
{
	this->fpn = num << this->fractBits;
}

Fixed::Fixed(const float num)
{
	this->fpn = roundf(num * (1 << this->fractBits));
}

Fixed&	Fixed::operator=(const Fixed &toCopy)
{
	if (this != &toCopy)
		this->setRawBits(toCopy.getRawBits());
	return *this;
}

Fixed	Fixed::operator*(const Fixed &obj)
{
	Fixed tmp;
	tmp.setRawBits((int) (((long) this->getRawBits() * (long) obj.getRawBits()) >> this->fractBits));
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed &obj)
{
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() - obj.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator+(const Fixed &obj)
{
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() + obj.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed &obj)
{
	Fixed tmp;
	if (obj.getRawBits() == 0)
	{
		std::cout << "Invalid operation" << std::endl;
		exit(1);
	}
	tmp.setRawBits((int) ((long) this->getRawBits() << this->fractBits) / (long) obj.getRawBits());
	return (tmp);
}

std::ostream&	operator<<(std::ostream& outStream, const Fixed& obj)
{
	outStream << obj.toFloat();
	return outStream;
}

bool	Fixed::operator>(const Fixed& obj)
{
	if (this->fpn > obj.fpn)
		return true;
	return false;
}

bool	Fixed::operator<(const Fixed& obj)
{
	if (this->fpn < obj.fpn)
		return true;
	return false;
}

bool	Fixed::operator==(const Fixed& obj)
{
	if (this->fpn == obj.fpn)
		return true;
	return false;
}

bool	Fixed::operator!=(const Fixed& obj)
{
	if (this->fpn != obj.fpn)
		return true;
	return false;
}

bool	Fixed::operator>=(const Fixed& obj)
{
	if (this->fpn >= obj.fpn)
		return true;
	return false;
}

bool	Fixed::operator<=(const Fixed& obj)
{
	if (this->fpn <= obj.fpn)
		return true;
	return false;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++(*this);
	return tmp;
}

Fixed&	Fixed::operator++()
{
	this->fpn++;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	this->fpn--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--(*this);
	return tmp;
}

Fixed::~Fixed()
{
}

int		Fixed::getRawBits( void ) const
{
	return (this->fpn);
}

void	Fixed::setRawBits( int const raw )
{
	this->fpn = raw;
}

float	Fixed::toFloat( void ) const
{
	return float(this->fpn) / (1 << this->fractBits);
}

int	Fixed::toInt( void ) const
{
	return this->fpn / (1 << this->fractBits);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}
