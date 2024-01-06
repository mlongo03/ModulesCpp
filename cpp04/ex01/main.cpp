#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	Animal* animals[4] = {new Cat(), new Cat(), new Dog(), new Dog()};
	dynamic_cast<Dog*>(animals[2])->getBrain()->setIdea(0, "wow");
	Dog* tmpDogPointer = dynamic_cast<Dog*>(animals[2]);
	std::cout << std::endl;
	Dog tmpDog = *tmpDogPointer;
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << std::endl;
		animals[i]->makeSound();
		delete animals[i];
	}
	std::cout << tmpDog.getBrain()->getIdea(0) << std::endl;
}
