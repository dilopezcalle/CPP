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
	// Create array of comments
	const std::string	comments[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	i;
	// Find comment's index
	for (i = 0; i < 4; i++)
	{
		if (level == comments[i])
			break ;
	}

	// Call corresponding function
	switch (i)
	{
	case 0:
		this->debug();
	case 1:
		this->info();
	case 2:
		this->warning();
	case 3:
		this->error();
		break ;
	default:
		std::cout << "\n[ Probably complaining about insignificant problems ]\n" << std::endl;
		break ;
	}
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