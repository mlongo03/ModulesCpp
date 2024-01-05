#ifndef Cat_HPP
#define Cat_HPP

#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat( void );
	Cat(const Cat &toCopy);
	~Cat();
	Cat& operator=(const Cat &toCopy);
	void	makeSound() const;
};

#endif
