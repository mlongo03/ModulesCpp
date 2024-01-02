#include <iostream>
#include <string>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor of " << this->name << " called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor of " << this->name << " called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (getHitPoints() <= 0)
		std::cout << "ScavTrap " << getName() << " can't attack because he has no more hit points" << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << "ScavTrap " << getName() << " can't attack because he has no more energy points" << std::endl;
	else
	{
		std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	setHitPoints(getHitPoints() - amount);
	std::cout << "ScavTrap " << getName() << " has taken " << amount << " points of damage (" << getHitPoints() << ")" << std::endl;
	if (getHitPoints() <= 0)
		std::cout << getName() << " is died!!!" << std::endl;
	return ;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (getHitPoints() <= 0)
		std::cout << "ScavTrap " << getName() << " can't be repaired because he has no more hit points" << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << "ScavTrap " << getName() << " can't be repaired because he has no more energy points" << std::endl;
	else
	{
		setHitPoints(getHitPoints() + amount);
		std::cout << "ScavTrap " << getName() << " has restored " << amount << " hit points (" << getHitPoints() << ")" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " is in gate keeper mode" << std::endl;
}
