#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	std::cout << std::endl;
	src->learnMateria(new Ice());
	std::cout << std::endl;
	src->learnMateria(new Cure());
	std::cout << std::endl;
	ICharacter* me = new Character("me");
	AMateria* tmp;
	std::cout << std::endl;
	tmp = src->createMateria("ice");
	std::cout << std::endl;
	me->equip(tmp);
	std::cout << std::endl;
	tmp = src->createMateria("cure");
	std::cout << std::endl;
	me->equip(tmp);
	std::cout << std::endl;
	tmp = src->createMateria("iron");
	std::cout << std::endl;
	me->equip(tmp);
	std::cout << std::endl;
	ICharacter* bob = new Character("bob");
	std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;
	me->unequip(0);
	std::cout << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;
	std::cout << std::endl;
	delete bob;
	std::cout << std::endl;
	delete me;
	std::cout << std::endl;
	delete src;
	std::cout << std::endl;
	return 0;
}
