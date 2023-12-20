
#include "Zombie.hpp"

int	main()
{
	Zombie* zombie = newZombie("fool");
	randomChump("alberto");
	zombie->announce();
	delete(zombie);
}
