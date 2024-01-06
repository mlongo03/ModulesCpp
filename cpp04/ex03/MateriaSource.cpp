#include <string>
#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->materias[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &toCopy)
{
	*this = toCopy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &toCopy)
{
	if (this == &toCopy)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i] != 0)
			delete this->materias[i];
		this->materias[i] = getMateria(i)->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i] != 0)
			delete this->materias[i];
	}
}

AMateria* MateriaSource::getMateria(int idx)
{
	return this->materias[idx];
}

void	MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;
	if (m == 0)
	{
		std::cout << "NULL isn't a valid materia" << std::endl;
		return ;
	}
	for (; i < 4; i++)
	{
		if (this->materias[i] == 0)
		{
			this->materias[i] = m;
			return ;
		}
	}
	std::cout << "the inventary is full" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	for (; i < 4; i++)
	{
		if (this->materias[i] != 0 && this->materias[i]->getType() == type)
			return this->materias[i]->clone();
	}
	std::cout << "the inventary does not contain that materia" << std::endl;
	return 0;
}
