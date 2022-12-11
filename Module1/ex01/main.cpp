#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream>

#include "Zombie.hpp"

int	main(void)
{
	int N = 5;

	// Create N zombies with name "pepe"
	std::cout << YELLOW << "\nSe crean " << N << " zombies con nombre 'pepe'\n" << RESET << std::endl;
	Zombie *zombies = zombieHorde(N, "pepe");

	// Pepes announces
	std::cout << YELLOW <<  "\nCada pepe se anuncia\n" << RESET << std::endl;
	for (int i = 0; i < N; i++)
		zombies[i].announce();

	// Destroy pepes
	std::cout << YELLOW << "\nSe liberan todos los zombies\n" << RESET << std::endl;
	delete []zombies;

	std::cout << std::endl;
	return (0);
}