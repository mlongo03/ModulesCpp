#ifndef WEAPON_CPP
#define WEAPON_CPP

#include <string>

class Weapon
{
private:
	std::string type;

public:
	Weapon();
	Weapon(std::string type);
	~Weapon();
	const std::string&	getType();
	void		setType(std::string type);
};

#endif
