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
	Dog(const Dog &toCopy);
	Dog& operator=(const Dog &toCopy);
	void	makeSound() const;
};

#endif
