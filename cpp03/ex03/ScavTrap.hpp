#ifndef ScavTrap_HPP
#define ScavTrap_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
public:
	ScavTrap( std::string name );
	~ScavTrap();
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	guardGate();
};

#endif
