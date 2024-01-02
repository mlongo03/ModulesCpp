#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <string>

class ClapTrap
{
protected:
	std::string	name;
	int			hitPoints;
	int			energyPoints;
	int			attackDamage;
public:
	ClapTrap( std::string name );
	~ClapTrap();
	std::string		getName( void );
	void			setName( std::string name );
	int				getEnergyPoints( void );
	void			setEnergyPoints( int energyPoints );
	int				getHitPoints( void );
	void			setHitPoints( int hitPoints );
	int				getAttackDamage( void );
	void			setAttackDamage( int attackDamage );
	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
};

#endif
