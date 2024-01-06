#ifndef Cat_HPP
#define Cat_HPP

#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat( void );
	~Cat();
	Cat(const Cat &toCopy);
	Cat& operator=(const Cat &toCopy);
	void	makeSound() const;
};

#endif
