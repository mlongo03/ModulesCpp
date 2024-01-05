#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor of called" << std::endl;
}


Dog::Dog(const Dog &toCopy) : Animal()
{
	*this = toCopy;
}

Dog& Dog::operator=(const Dog &toCopy)
{
	if (this == &toCopy)
		return (*this);
	this->setType(toCopy.getType());
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "bau bau" << std::endl;
}
