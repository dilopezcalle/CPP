#include "WrongAnimal.hpp"

// ===== Constructors =====
WrongAnimal::WrongAnimal() : _type("NULL")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
	std::cout << "WrongAnimal copy contructor called" << std::endl;
	return ;
}

// ===== Destructor =====
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
	return ;
}

// ===== Operators =====
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src)
{
	this->_type = src.getType();
	return (*this);
}

// ===== Getters =====
std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

// ===== Setters =====
void	WrongAnimal::setType(std::string type)
{
	this->_type = type;
	return ;
}

// ===== Methods =====
int	WrongAnimal::makeSound(void) const
{
	std::cout << "speechless..." << std::endl;
	return (0);
}