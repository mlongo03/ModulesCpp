#ifndef DiamondTrap_HPP
#define DiamondTrap_HPP

#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	DiamondTrap( std::string name );
	~DiamondTrap();
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	highFivesGuys(void);
	void	whoAmI();
};

#endif
