#ifndef Brain_HPP
#define Brain_HPP

#include <string>
#include "Animal.hpp"

class Brain
{
private:
	std::string ideas[100];
public:
	Brain( void );
	~Brain();
};

#endif
