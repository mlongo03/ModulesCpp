#ifndef WrongCat_HPP
#define WrongCat_HPP

#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat( void );
	~WrongCat();
	WrongCat(const WrongCat &toCopy);
	WrongCat& operator=(const WrongCat &toCopy);
	void	makeSound() const;
};

#endif
