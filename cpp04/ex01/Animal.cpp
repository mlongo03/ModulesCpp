#include <iostream>
#include <string>
#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	return ;
}

std::string		Animal::getType( void ) const
{
	return this->type;
}

void	Animal::setType( std::string type )
{
	this->type = type;
}
