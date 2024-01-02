#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main( void )
{
	ClapTrap	alberto("alberto"), mario("mario");

	alberto.attack(mario.getName());
	mario.takeDamage(alberto.getAttackDamage());
	mario.attack(alberto.getName());
	alberto.takeDamage(mario.getAttackDamage());

	ScavTrap	maurizio("maurizio");
	maurizio.guardGate();
	maurizio.attack(alberto.getName());
	alberto.takeDamage(maurizio.getAttackDamage());
	maurizio.attack(mario.getName());
	mario.takeDamage(maurizio.getAttackDamage());
	return (0);
}
