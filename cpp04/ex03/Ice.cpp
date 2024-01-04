#include "AMateria.hpp"
#include "Ice.hpp"
#include <string>


Ice::Ice(std::string const & type) : AMateria(type)
{
	;
}

Ice::~Ice()
{
	std::cout << "Ice constructor called" << std::endl;
}

AMateria* Ice::clone() const
{
	Ice *tmp = new Ice(type);
	return (tmp);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
