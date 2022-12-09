#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream>

#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

int	main(void)
{
	// Test in STACK with randomChump
	std::cout << YELLOW << "\nSe crea un Zombie en el Stack:\n" << RESET << std::endl;
	randomChump("Paco");

	// Test in HEAP with newZombie
	Zombie	*zombie;
	std::cout << YELLOW << "\nSe crea un Zombie en el Heap:\n" << RESET << std::endl;
	zombie = newZombie("Lupita");
	zombie->announce();

	// Without this line, Lupita will 
	delete zombie;
	return (0);
}