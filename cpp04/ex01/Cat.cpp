#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &toCopy) : Animal()
{
	this->brain = new Brain();
	*this = toCopy;
}

Cat& Cat::operator=(const Cat &toCopy)
{
	if (this == &toCopy)
		return (*this);
	this->setType(toCopy.getType());
	this->setBrain(toCopy.getBrain());
	return (*this);
}

Brain* Cat::getBrain() const
{
	return this->brain;
}

void	Cat::setBrain(Brain* brain)
{
	*this->brain = *brain;
}

void	Cat::makeSound() const
{
	std::cout << "miao miao" << std::endl;
}
