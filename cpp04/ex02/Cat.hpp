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
	void	makeSound() const;
};

#endif
