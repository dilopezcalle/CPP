#include "AAnimal.hpp"

// ===== Constructors =====
AAnimal::AAnimal() : _type("NULL")
{
	std::cout << "AAnimal default constructor called" << std::endl;
	return ;
}

AAnimal::AAnimal(const AAnimal &src)
{
	*this = src;
	std::cout << "AAnimal copy contructor called" << std::endl;
	return ;
}

// ===== Destructor =====
AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
	return ;
}

// ===== Operators =====
AAnimal	&AAnimal::operator=(const AAnimal &src)
{
	this->_type = src.getType();
	return (*this);
}

// ===== Getters =====
std::string	AAnimal::getType(void) const
{
	return (this->_type);
}

// ===== Setters =====
void	AAnimal::setType(std::string type)
{
	this->_type = type;
	return ;
}

// ===== Methods =====
int	AAnimal::makeSound(void) const
{
	std::cout << "speechless..." << std::endl;
	return (0);
}