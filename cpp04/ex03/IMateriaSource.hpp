#ifndef IMATERIASURCE_HPP
#define IMATERIASURCE_HPP

#include <string>
#include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource();
	virtual void learnMateria(AMateria* m) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
