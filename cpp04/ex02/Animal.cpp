#include <iostream>
#include <string>
#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &toCopy)
{
	*this = toCopy;
}

Animal& Animal::operator=(const Animal &toCopy)
{
	if (this == &toCopy)
		return (*this);
	this->setType(toCopy.getType());
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string		Animal::getType( void ) const
{
	return this->type;
}

void	Animal::setType( std::string type )
{
	this->type = type;
}
