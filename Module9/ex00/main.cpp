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
		std::cout << RED << "\n===== Argumentos inválidos =====" << RESET << "\n\n";
		return (0);
	}
	(void)av;
	BitcoinExchange	btc;
	if (btc.getNumDates() == 0)
		std::cout << RED << "\n===== Problemas al leer la base de datos =====" << RESET << "\n\n";
	if (btc.printExchangeRate(av[1]))
		std::cout << RED << "\n===== El archivo \"" << av[1]
		<< "\" no existe o tiene formato inválido =====" << RESET << "\n\n";
	return (0);
}
