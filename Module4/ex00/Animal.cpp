#include "Animal.hpp"

// ===== Constructors =====
Animal::Animal() : _type("NULL")
{
	std::cout << "Animal default constructor called" << std::endl;
	return ;
}

Animal::Animal(const Animal &src)
{
	*this = src;
	std::cout << "Animal copy contructor called" << std::endl;
	return ;
}

// ===== Destructor =====
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
	return ;
}

// ===== Operators =====
Animal	&Animal::operator=(const Animal &src)
{
	this->_type = src.getType();
	return (*this);
}

// ===== Getters =====
std::string	Animal::getType(void) const
{
	return (this->_type);
}

// ===== Setters =====
void	Animal::setType(std::string type)
{
	this->_type = type;
	return ;
}

// ===== Methods =====
int	Animal::makeSound(void) const
{
	std::cout << "speechless..." << std::endl;
	return (0);
}