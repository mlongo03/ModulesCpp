#ifndef CURE_HPP
#define CURE_HPP

#include <string>
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	~Cure();
	Cure(const Cure &toCopy);
	Cure& operator=(const Cure &toCopy);
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
