#include <iostream>
#include <string>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name")
{
	this->setName(name);
	std::cout << "DiamondTrap constructor of " << this->name << " called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor of " << this->name << " called" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	if (getHitPoints() <= 0)
		std::cout << "DiamondTrap " << getName() << " can't attack because he has no more hit points" << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << "DiamondTrap " << getName() << " can't attack because he has no more energy points" << std::endl;
	else
	{
		std::cout << "DiamondTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	setHitPoints(getHitPoints() - amount);
	std::cout << "DiamondTrap " << getName() << " has taken " << amount << " points of damage (" << getHitPoints() << ")" << std::endl;
	if (getHitPoints() <= 0)
		std::cout << getName() << " is died!!!" << std::endl;
	return ;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (getHitPoints() <= 0)
		std::cout << "DiamondTrap " << getName() << " can't be repaired because he has no more hit points" << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << "DiamondTrap " << getName() << " can't be repaired because he has no more energy points" << std::endl;
	else
	{
		setHitPoints(getHitPoints() + amount);
		std::cout << "DiamondTrap " << getName() << " has restored " << amount << " hit points (" << getHitPoints() << ")" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
}

void	DiamondTrap::highFivesGuys(void)
{
	std::cout << "DiamondTrap " << this->getName() << " smash a positive high five!" << std::endl;
}
