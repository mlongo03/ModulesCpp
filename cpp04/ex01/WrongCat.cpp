#include <iostream>
#include <string>
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &toCopy) : WrongAnimal()
{
	*this = toCopy;
}

WrongCat& WrongCat::operator=(const WrongCat &toCopy)
{
	if (this == &toCopy)
		return (*this);
	this->setType(toCopy.getType());
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "mouuu mouu" << std::endl;
}
