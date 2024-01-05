#include <string>
#include <iostream>
#include "IMateriaSource.hpp"

IMateriaSource::~IMateriaSource()
{
	std::cout << "IMateriaSource destructor called" << std::endl;
}
