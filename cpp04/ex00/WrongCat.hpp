#ifndef WrongCat_HPP
#define WrongCat_HPP

#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat( void );
	~WrongCat();
	void	makeSound() const;
};

#endif
