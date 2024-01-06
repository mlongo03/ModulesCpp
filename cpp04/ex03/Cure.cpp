#include "AMateria.hpp"
#include "Cure.hpp"
#include <string>


Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &toCopy) : AMateria("cure")
{
	*this = toCopy;
}

Cure& Cure::operator=(const Cure &toCopy)
{
	if (this == &toCopy)
		return (*this);
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
	AMateria *tmp = new Cure();
	return (tmp);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
