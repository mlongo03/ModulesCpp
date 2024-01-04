#ifndef Dog_HPP
#define Dog_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* brain;

public:
	Dog( void );
	~Dog();
	void	makeSound() const;
};

#endif
