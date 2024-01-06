#include <iostream>
#include "Character.hpp"

Character::Character(std::string name) : name(name)
{
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->materias[i] = 0;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i] != 0)
			delete this->materias[i];
	}
	std::cout << "Character destructor called" << std::endl;
}

Character::Character(Character &toCopy)
{
	(*this) = toCopy;
}
Character& Character::operator=(Character &toCopy)
{
	this->name = toCopy.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i] != 0)
			delete this->materias[i];
		this->materias[i] = toCopy.getMaterias()[i];
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return this->name;
}

AMateria** Character::getMaterias()
{
	return this->materias;
}

void Character::equip(AMateria* m)
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

void Character::unequip(int idx)
{
	if (this->materias[idx] != 0)
	{
		delete this->materias[idx];
		this->materias[idx] = 0;
	}
	else
		std::cout << "the slot is not initialized" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (this->materias[idx] != 0)
		this->materias[idx]->use(target);
	else
		std::cout << "the slot is not initialized" << std::endl;
}
