#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
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

	FragTrap	carlone("carlone");
	carlone.highFivesGuys();
	for (int i = 0; i < 4; i++)
	{
		carlone.attack(maurizio.getName());
		maurizio.takeDamage(carlone.getAttackDamage());
	}
	DiamondTrap	alfredo("Alfredo");
	alfredo.whoAmI();
	alfredo.attack(carlone.getName());
	carlone.takeDamage(alfredo.getAttackDamage());
	return (0);
}
