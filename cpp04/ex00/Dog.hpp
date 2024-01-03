#ifndef Dog_HPP
#define Dog_HPP

#include <string>
#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog( void );
	~Dog();
	void	makeSound() const;
};

#endif
