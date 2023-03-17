#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream>
#include <ctime>
#include <map>

#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << RESET << " ===== Argumentos inválidos =====" << RESET << "\n";
		return (0);
	}
	(void)av;
	try
	{
		BitcoinExchange	btc;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
