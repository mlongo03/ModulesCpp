#ifndef easyfind_HPP
#define easyfind_HPP

#include <iostream>
#include <algorithm>
#include <iterator>

class OccurrenceNotFound : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Occurrence not found";
		}
};

template<typename T>
void	easyfind(T cont, int integer)
{
	if(cont.find(integer) == cont.end())
		throw OccurrenceNotFound();
	std::cout << "Occurrence " << integer << " has been found" << std::endl;
}

#endif
