#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include <iostream>

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* i = new Dog();
	const Animal* j = new Cat();
	const WrongAnimal *p_cat = new WrongCat();

	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound();
	meta->makeSound();
	std::cout << "Wrong cat" << std::endl;
	p_cat->makeSound();

	delete meta;
	delete i;
	delete j;
	delete p_cat;
	return (0);
}
