#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &toCopy)
{
	*this = toCopy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &toCopy)
{
	if (this == &toCopy)
		return (*this);
	this->setType(toCopy.getType());
	return (*this);
}

std::string		WrongAnimal::getType( void ) const
{
	return this->type;
}

void	WrongAnimal::setType( std::string type )
{
	this->type = type;
}
