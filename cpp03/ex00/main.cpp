#include "ClapTrap.hpp"
#include <iostream>

int main( void )
{
	ClapTrap	alberto("alberto"), mario("mario");

	alberto.setAttackDamage(2);
	mario.setAttackDamage(2);
	alberto.attack(mario.getName());
	mario.takeDamage(alberto.getAttackDamage());
	mario.attack(alberto.getName());
	alberto.takeDamage(mario.getAttackDamage());

	alberto.attack(mario.getName());
	mario.takeDamage(alberto.getAttackDamage());
	mario.attack(alberto.getName());
	alberto.takeDamage(mario.getAttackDamage());

	alberto.attack(mario.getName());
	mario.takeDamage(alberto.getAttackDamage());
	mario.attack(alberto.getName());
	alberto.takeDamage(mario.getAttackDamage());

	alberto.attack(mario.getName());
	mario.takeDamage(alberto.getAttackDamage());
	mario.attack(alberto.getName());
	alberto.takeDamage(mario.getAttackDamage());

	mario.beRepaired(2);
	alberto.attack(mario.getName());
	mario.takeDamage(alberto.getAttackDamage());
	mario.attack(alberto.getName());
	alberto.takeDamage(mario.getAttackDamage());

	return (0);
}
