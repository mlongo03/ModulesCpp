#include <iostream>
#include <string>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name")
{
	this->name = name;
	std::cout << "DiamondTrap constructor of " << this->name << " called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor of " << this->name << " called" << std::endl;
}

void		DiamondTrap::whoAmI(void)
{
	std::cout << "Diamond name: " << this->name << std::endl;
	std::cout << "Clap name: " << ClapTrap::name << std::endl;
}
