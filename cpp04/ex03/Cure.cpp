#include "AMateria.hpp"
#include "Cure.hpp"
#include <string>


Cure::Cure(std::string const & type) : AMateria(type)
{
	;
}

Cure::~Cure()
{
	std::cout << "Cure constructor called" << std::endl;
}

AMateria* Cure::clone() const
{
	Cure *tmp = new Cure(type);
	return (tmp);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
