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
void	Dog::makeSound() const
{
	std::cout << "bau bau" << std::endl;
}
