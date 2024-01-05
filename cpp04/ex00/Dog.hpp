#ifndef Dog_HPP
#define Dog_HPP

#include <string>
#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog( void );
	Dog(const Dog &toCopy);
	~Dog();
	Dog& operator=(const Dog &toCopy);
	void	makeSound() const;
};

#endif
