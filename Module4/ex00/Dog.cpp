#include "Dog.hpp"

// ===== Constructors =====
Dog::Dog()
{
	this->setType("Dog");
	std::cout << "Dog default constructor called" << std::endl;
	return ;
}

Dog::Dog(const Dog &src)
{
	*this = src;
	std::cout << "Dog copy contructor called" << std::endl;
	return ;
}

// ===== Destructor =====
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

// ===== Operators =====
Dog	&Dog::operator=(const Dog &src)
{
	this->_type = src.getType();
	return (*this);
}

// ===== Methods =====
int	Dog::makeSound(void) const
{
	std::cout << "woof-woof!" << std::endl;
	return (0);
}