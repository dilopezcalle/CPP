#include "Harl.hpp"

Harl::Harl()
{
	return ;
}

Harl::~Harl()
{
	return ;
}

void	Harl::complain(std::string level)
{
	// Create array of functions
	typedef void	(Harl::*Functions)(void);
	Functions	functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	// Create array of comments
	std::string	comments[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	i;
	for (i = 0; i < 4; i++)
	{
		if (level == comments[i])
		{
			(this->*functions[i])();
			break ;
		}
	}
	if (i == 4)
		std::cout << "\n[ Probably complaining about insignificant problems ]\n" << std::endl;
}

void	Harl::debug()
{
	std::cout
	<< "\n[ DEBUG ]\n"
	<< "I love having extra bacon for my 7XL-double-cheese-triple-picklespecial-ketchup burger. I really do!\n"
	<< std::endl;
	return ;
}

void	Harl::info()
{
	std::cout
	<< "\n[ INFO ]\n"
	<< "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n"
	<< std::endl;
	return ;
}

void	Harl::warning()
{
	std::cout
	<< "\n[ WARNING ]\n"
	<< "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n"
	<< std::endl;
	return ;
}

void	Harl::error()
{
	std::cout
	<< "\n[ ERROR ]\n"
	<< "This is unacceptable! I want to speak to the manager now.\n"
	<< std::endl;
	return ;
}