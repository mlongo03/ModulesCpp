#include "iter.hpp"
#include <iostream>

int main( void )
{
	int numbers[3] = {1, 2, 3};

	iter(numbers, 3, printArray<int>);
	iter("ciao", 4, printArray<char>);
	return 0;
}
