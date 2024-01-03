#ifndef FragTrap_HPP
#define FragTrap_HPP

#include <string>
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
public:
	FragTrap( std::string name );
	~FragTrap();
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	highFivesGuys(void);
};

#endif
