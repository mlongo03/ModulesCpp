#include <string>
#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
	this->type = type;
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &toCopy)
{
	*this = toCopy;
}

AMateria& AMateria::operator=(const AMateria &toCopy)
{
	if (this == &toCopy)
		return (*this);
	this->type = toCopy.getType();
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
