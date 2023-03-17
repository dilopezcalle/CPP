#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <ctime>
# include <map>

class BitcoinExchange
{
private:
	// ===== Attributes =====
	std::map<std::string, double>	_dataBase;

	// ===== Private methods =====
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange	&operator=(const BitcoinExchange &src);

public:
	// ===== Constructor =====
	BitcoinExchange();

	// ===== Destructor =====
	~BitcoinExchange();

};

#endif