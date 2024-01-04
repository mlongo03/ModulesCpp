#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor of called" << std::endl;
	delete this->brain;
}
void	Dog::makeSound() const
{
	std::cout << "bau bau" << std::endl;
}
