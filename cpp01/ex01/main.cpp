
#include "Zombie.hpp"

int	main()
{
	Zombie* zombies = zombieHorde(6, "pippo");
	for (int i = 0; i < 6; i++)
	{
		zombies->announce();
		zombies += 1;
	}
}
