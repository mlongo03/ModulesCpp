#ifndef Cat_HPP
#define Cat_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* brain;

public:
	Cat( void );
	~Cat();
	Cat(const Cat &toCopy);
	Cat& operator=(const Cat &toCopy);
	Brain*	getBrain() const;
	void	setBrain(Brain* brain);
	void	makeSound() const;
};

#endif
