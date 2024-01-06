#include "AMateria.hpp"
#include "Ice.hpp"
#include <string>


Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &toCopy) : AMateria("ice")
{
	*this = toCopy;
}

Ice& Ice::operator=(const Ice &toCopy)
{
	if (this == &toCopy)
		return (*this);
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
	Ice *tmp = new Ice();
	return (tmp);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
