#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream>
#include <vector>

#include "PmergeMe.hpp"

int main(int ac, char *av[])
{
	if (ac < 2)
	{
		std::cout << RED << "\n===== Argumentos inválidos =====" << RESET << "\n\n";
		return (0);
	}

	mergeSort(av + 1);

	return (0);
}
