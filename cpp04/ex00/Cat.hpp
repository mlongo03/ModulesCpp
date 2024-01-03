#ifndef Cat_HPP
#define Cat_HPP

#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat( void );
	~Cat();
	void	makeSound() const;
};

#endif
