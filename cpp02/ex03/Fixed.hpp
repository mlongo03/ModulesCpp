#ifndef Fixed_HPP
#define Fixed_HPP

#include <string>

class Fixed
{
private:
	int					fpn;
	static const int	fractBits;

public:
	Fixed();
	Fixed(const Fixed &toCopy);
	Fixed(const int num);
	Fixed(const float num);
	~Fixed();
	bool			operator>(const Fixed& obj);
	bool			operator<(const Fixed& obj);
	bool			operator==(const Fixed& obj);
	bool			operator!=(const Fixed& obj);
	bool			operator>=(const Fixed& obj);
	bool			operator<=(const Fixed& obj);
	Fixed&			operator=(const Fixed &toCopy);
	Fixed			operator*(const Fixed &obj);
	Fixed			operator-(const Fixed &obj);
	Fixed			operator+(const Fixed &obj);
	Fixed			operator/(const Fixed &obj);
	Fixed			operator++(int);
	Fixed&			operator++();
	Fixed&			operator--();
	Fixed			operator--(int);
	int				getRawBits( void ) const;
	void			setRawBits( int const raw );
	float			toFloat( void ) const;
	int				toInt( void ) const;
	static Fixed&	min(Fixed& a, Fixed& b);
	static const	Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed&	max(Fixed& a, Fixed& b);
	static const	Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);


#endif
