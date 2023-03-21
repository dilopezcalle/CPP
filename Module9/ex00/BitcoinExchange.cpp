#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <limits>

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
		(line.substr(0, 10), std::atof(line.substr(line.find(",") + 1).c_str())));
		this->_numDates++;
	}

	return ;
}

// ===== Destructor =====
BitcoinExchange::~BitcoinExchange()
{
	this->_dataBase.clear();
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
	std::string		new_bottom_date;
	std::string		new_top_date;
	std::string		line;
	std::string		date;
	double			value;
	int				i = 0;
	int				j = 0;

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
		if (!this->checkLineFormat(line))
			continue ;

		date = line.substr(0, line.find(" | "));
		value = std::atof(line.substr(line.find(" | ") + 3, line.length()).c_str());
		new_bottom_date = date;
		new_top_date = date;

		// Check previous date
		while (	new_bottom_date >= this->_dataBase.begin()->first
				&& this->_dataBase.find(new_bottom_date) == this->_dataBase.end())
		{
			new_bottom_date = this->subtractDay(new_bottom_date);
			i++;
		}
		
		// Check later date
		std::map<std::string, double>::iterator	end = this->_dataBase.end();
		end--;
		while (	new_top_date <= end->first
				&& this->_dataBase.find(new_top_date) == this->_dataBase.end())
		{
			new_top_date = this->additionDay(new_top_date);
			j++;
		}

		if ((i == 0 && this->_dataBase.find(new_bottom_date) != this->_dataBase.end()) || (i < j && i > 0))
			std::cout << date << " =>= " << value << " = "
			<< this->_dataBase[new_bottom_date] * value << "\n";
		else
			std::cout << date << " => " << value << " = "
			<< this->_dataBase[new_top_date] * value << "\n";
	}
	return (0);
}

// ===== Private functions =====
std::string	BitcoinExchange::subtractDay(std::string date)
{
	std::tm timeinfo = {};
	strptime(date.c_str(), "%Y-%m-%d", &timeinfo);

	timeinfo.tm_mday--;
	std::mktime(&timeinfo);

	char buffer[11];
	std::strftime(buffer, 11, "%Y-%m-%d", &timeinfo);
	return (std::string(buffer));
}

std::string	BitcoinExchange::additionDay(std::string date)
{
	std::tm timeinfo = {};
	strptime(date.c_str(), "%Y-%m-%d", &timeinfo);

	timeinfo.tm_mday++;
	std::mktime(&timeinfo);

	char buffer[11];
	std::strftime(buffer, 11, "%Y-%m-%d", &timeinfo);
	return (std::string(buffer));
}

bool		BitcoinExchange::checkLineFormat(std::string line)
{
	std::string		date;
	std::string		value;

	if (line.find(" | ") > line.length())
	{
		std::cout << "Error: Separador incorrecto" << "\n";
		return (false);
	}

	date = line.substr(0, line.find(" | "));
	value = line.substr(line.find(" | ") + 3, line.length());

	if (!this->checkDateFormat(date))
	{
		std::cout << "Error: Formato o fecha inválida" << "\n";
		return (false);
	}

	double	num = std::atof(value.c_str());
	if (std::atoi(value.c_str()) == 0 && (value.length() > 1 || value.c_str()[0] != '0'))
	{
		std::cout << "Error: El valor no es un número válido" << "\n";
		return (false);
	}
	if ((num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max()) ||
		(num < 0 || num > 1000))
	{
		std::cout << "Error: El valor no está entre 0 y 1000" << "\n";
		return (false);
	}

	return (true);
}

bool		BitcoinExchange::checkDateFormat(std::string date)
{
	int year, month, day;

	// if (date < this->_dataBase.begin()->first)
	// 	return (false);
	if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
		return (false);
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	if (month == 2)
	{
		bool isLeapYear = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
		if (day > 29 || (day == 29 && !isLeapYear))
			return (false);
	}
	return (true);
}