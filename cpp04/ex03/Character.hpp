#ifndef Character_HPP
#define Character_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string name;
	AMateria *materias[4];
public:
	Character(std::string name);
	~Character();
	Character(Character &toCopy);
	Character& operator=(Character &toCopy);
	std::string const & getName() const;
	AMateria** getMaterias();
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, Character& target);
};

#endif
