#ifndef CURE_HPP
#define CURE_HPP

#include <string>
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(std::string const & type);
	~Cure();
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
