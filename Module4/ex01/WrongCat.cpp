#include "WrongCat.hpp"

// ===== Constructors =====
WrongCat::WrongCat()
{
	this->setType("WrongCat");
	std::cout << "WrongCat default constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat &src)
{
	*this = src;
	std::cout << "WrongCat copy contructor called" << std::endl;
	return ;
}

// ===== Destructor =====
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}

// ===== Operators =====
WrongCat	&WrongCat::operator=(const WrongCat &src)
{
	this->_type = src.getType();
	return (*this);
}

// ===== Methods =====
int	WrongCat::makeSound(void) const
{
	std::cout << "meow~" << std::endl;
	return (0);
}