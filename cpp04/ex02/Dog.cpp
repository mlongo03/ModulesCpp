#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &toCopy) : Animal()
{
	this->brain = new Brain();
	*this = toCopy;
}

Dog& Dog::operator=(const Dog &toCopy)
{
	if (this == &toCopy)
		return (*this);
	this->setType(toCopy.getType());
	this->setBrain(toCopy.getBrain());
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor of called" << std::endl;
}

Brain* Dog::getBrain() const
{
	return this->brain;
}

void	Dog::setBrain(Brain* brain)
{
	*this->brain = *brain;
}

void	Dog::makeSound() const
{
	std::cout << "bau bau" << std::endl;
}
