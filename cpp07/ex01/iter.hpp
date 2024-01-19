#ifndef iter_HPP
#define iter_HPP

#include <iostream>

template <typename T>
void	iter(T array[], int length, void (*f)(T const &))
{
	for (int i = 0; i < length; ++i)
		f(array[i]);
}

template <typename T>
void	printArray(T const &x)
{
	std::cout << x << std::endl;
}

#endif
