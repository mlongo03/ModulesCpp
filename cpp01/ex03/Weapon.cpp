#include <iostream>
#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string&	Weapon::getType()
{
	return (this->type);
}
