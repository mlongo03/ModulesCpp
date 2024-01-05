#include "AMateria.hpp"
#include "Cure.hpp"
#include <string>


Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
	Cure *tmp = new Cure();
	return (tmp);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
