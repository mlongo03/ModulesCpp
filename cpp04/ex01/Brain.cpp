#include <iostream>
#include <string>
#include "Brain.hpp"
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->setIdea(i, "nothing");
}

Brain::Brain(const Brain &toCopy)
{
	*this = toCopy;
}

Brain& Brain::operator=(const Brain &toCopy)
{
	if (this == &toCopy)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->setIdea(i, toCopy.getIdea(i));
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdea(int idx, std::string idea)
{
	this->ideas[idx] = idea;
}

std::string Brain::getIdea(int idx) const
{
	return this->ideas[idx];
}

