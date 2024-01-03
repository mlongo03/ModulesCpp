#ifndef DiamondTrap_HPP
#define DiamondTrap_HPP

#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{

private:
	std::string	name;
	using		FragTrap::hitPoints;
	using		ScavTrap::energyPoints;
	using		FragTrap::attackDamage;
public:
	DiamondTrap( std::string name );
	~DiamondTrap();
	using	ScavTrap::attack;
	void	whoAmI();
};

#endif
