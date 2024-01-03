#include <iostream>
#include <string>
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor of " << this->name << " called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor of " << this->name << " called" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (getHitPoints() <= 0)
		std::cout << "FragTrap " << getName() << " can't attack because he has no more hit points" << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << "FragTrap " << getName() << " can't attack because he has no more energy points" << std::endl;
	else
	{
		std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
}

void	FragTrap::takeDamage(unsigned int amount)
{
	setHitPoints(getHitPoints() - amount);
	std::cout << "FragTrap " << getName() << " has taken " << amount << " points of damage (" << getHitPoints() << ")" << std::endl;
	if (getHitPoints() <= 0)
		std::cout << getName() << " is died!!!" << std::endl;
	return ;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (getHitPoints() <= 0)
		std::cout << "FragTrap " << getName() << " can't be repaired because he has no more hit points" << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << "FragTrap " << getName() << " can't be repaired because he has no more energy points" << std::endl;
	else
	{
		setHitPoints(getHitPoints() + amount);
		std::cout << "FragTrap " << getName() << " has restored " << amount << " hit points (" << getHitPoints() << ")" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " smash a positive high five!" << std::endl;
}
