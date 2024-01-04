#ifndef AMateria_HPP
#define AMateria_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string type;
public:
	AMateria(std::string const & type);
	virtual ~AMateria();
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
