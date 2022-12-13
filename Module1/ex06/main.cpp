#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream>

#include "Harl.hpp"

int	main(int argn, char *argv[])
{
	// Check number arguments
	if (argn > 2 || argn == 1)
	{
		std::cout << RED << "\nNumero de argumentos inválidos\n" << RESET << std::endl;
		return (1);
	}

	// Create a Harl
	Harl harl;
	harl.complain(argv[1]);
	return (0);
}