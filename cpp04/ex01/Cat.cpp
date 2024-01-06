#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &toCopy) : Animal()
{
	*this = toCopy;
}

Cat& Cat::operator=(const Cat &toCopy)
{
	if (this == &toCopy)
		return (*this);
	this->setType(toCopy.getType());
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "miao miao" << std::endl;
}
