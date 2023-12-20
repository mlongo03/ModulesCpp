#include "Zombie.hpp"
#include <string>
#include <new>

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* zombie = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombie[i].setName(name);
	return (zombie);
}
