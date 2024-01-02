#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "ClapTrap constructor of " << this->name << " called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor of " << this->name << " called" << std::endl;
}

std::string		ClapTrap::getName( void )
{
	return this->name;
}

void	ClapTrap::setName( std::string name )
{
	this->name = name;
}


int		ClapTrap::getEnergyPoints( void )
{
	return this->energyPoints;
}

void	ClapTrap::setEnergyPoints( int energyPoints )
{
	this->energyPoints = energyPoints;
}

int		ClapTrap::getHitPoints( void )
{
	return this->hitPoints;
}

void	ClapTrap::setHitPoints( int hitPoints )
{
	this->hitPoints = hitPoints;
}

int		ClapTrap::getAttackDamage( void )
{
	return this->attackDamage;
}

void	ClapTrap::setAttackDamage( int attackDamage )
{
	this->attackDamage = attackDamage;
}

void	ClapTrap::attack(const std::string& target)
{
	if (getHitPoints() <= 0)
		std::cout << "ClapTrap " << getName() << " can't attack because he has no more hit points" << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << "ClapTrap " << getName() << " can't attack because he has no more energy points" << std::endl;
	else
	{
		std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	setHitPoints(getHitPoints() - amount);
	std::cout << "ClapTrap " << getName() << " has taken " << amount << " points of damage (" << getHitPoints() << ")" << std::endl;
	if (getHitPoints() <= 0)
		std::cout << getName() << " is died!!!" << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (getHitPoints() <= 0)
		std::cout << "ClapTrap " << getName() << " can't be repaired because he has no more hit points" << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << "ClapTrap " << getName() << " can't be repaired because he has no more energy points" << std::endl;
	else
	{
		setHitPoints(getHitPoints() + amount);
		std::cout << "ClapTrap " << getName() << " has restored " << amount << " hit points (" << getHitPoints() << ")" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
}
