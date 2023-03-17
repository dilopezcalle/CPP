#include "BitcoinExchange.hpp"

#include <fstream>

// ===== Constructor =====
BitcoinExchange::BitcoinExchange()
{
	std::ifstream	file("data.csv");
	std::string		data_base;
	std::string		line;

	if (!file)
		throw std::exception();

	while (std::getline(file, line))
		data_base += line + "\n";
	std::cout << data_base << "\n";
	return ;
}

// ===== Destructor =====
BitcoinExchange::~BitcoinExchange()
{

}