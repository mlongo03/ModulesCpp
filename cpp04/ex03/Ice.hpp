#ifndef ICE_HPP
#define ICE_HPP

#include <string>
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	~Ice();
	Ice(const Ice &toCopy);
	Ice& operator=(const Ice &toCopy);
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
