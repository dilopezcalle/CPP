#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Contructor called" << std::endl;
	return ;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " destroyed" << std::endl;
	return ;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
	return ;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}