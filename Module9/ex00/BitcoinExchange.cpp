#include "BitcoinExchange.hpp"

#include <ctime>
#include <fstream>
#include <sstream>

// ===== Constructor =====
BitcoinExchange::BitcoinExchange() : _numDates(0)
{
	std::ifstream	file("data.csv");
	std::string		line;

	if (!file)
		return ;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		this->_dataBase.insert(std::pair<std::string, double>
		(line.substr(0, 10), std::stof(line.substr(line.find(",") + 1))));
		this->_numDates++;
	}
	return ;
}

// ===== Destructor =====
BitcoinExchange::~BitcoinExchange()
{
	return ;
}

// ===== Getters =====
unsigned int	BitcoinExchange::getNumDates(void)
{
	return (this->_numDates);
}

// ===== Methods =====
int	BitcoinExchange::printExchangeRate(char *name_file)
{
	std::ifstream	file(name_file);
	std::string		line;
	std::string		date;
	std::string		value;

	if (!file)
		return (1);

	(void)name_file;
	std::getline(file, line);
	if (line.find(" | ") > line.length())
		return (1);
	if (line != "date | value")
		return (1);

	while (std::getline(file, line))
	{
		if (line.find(" | ") > line.length())
			std::cout << "Error: Separador incorrecto" << "\n";
		else
		{
			date = line.substr(0, line.find(" | "));
			value = line.substr(line.find(" | ") + 3, line.length());

			std::cout << "fecha: " << date << "\nvalor: " << value << "\n";
			if (!this->checkDateFormat(date))
				std::cout << "Error: Formato de fecha inválido" << "\n";
			else
			{
				
			}
		}
	}
	return (0);
}

// ===== Private functions =====
std::string	BitcoinExchange::subtractDay(std::string date)
{
	struct tm date_tm;
	std::stringstream ss(date);

	ss >> std::get_time(&date_tm, "%Y-%m-%d");
	date_tm.tm_mday--;
	mktime(&date_tm);

	char buffer[80];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d", &date_tm);

	std::string new_date(buffer);
	return (new_date);
}

bool		BitcoinExchange::checkDateFormat(std::string date)
{
	struct tm date_tm;

	std::stringstream ss(date);
	ss >> std::get_time(&date_tm, "%Y-%m-%d");

	if (ss.eof() && mktime(&date_tm) != -1)
		return (true);
	return (false);
}