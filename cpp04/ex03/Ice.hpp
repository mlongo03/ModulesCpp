#ifndef ICE_HPP
#define ICE_HPP

#include <string>
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(std::string const & type);
	~Ice();
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
