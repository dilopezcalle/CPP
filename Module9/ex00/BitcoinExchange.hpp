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
	unsigned int					_numDates;

	// ===== Private methods =====
	std::string	subtractDay(std::string date);
	std::string	additionDay(std::string date);
	bool		checkDateFormat(std::string date);
	bool		checkLineFormat(std::string line);

	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange	&operator=(const BitcoinExchange &src);

public:
	// ===== Constructor =====
	BitcoinExchange();

	// ===== Destructor =====
	~BitcoinExchange();

	// ===== Getters =====
	unsigned int	getNumDates(void);

	// ===== Methods =====
	int	printExchangeRate(char *name_file);

};

#endif