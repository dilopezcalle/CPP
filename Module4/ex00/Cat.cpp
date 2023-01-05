#include "Cat.hpp"

// ===== Constructors =====
Cat::Cat()
{
	this->setType("Cat");
	std::cout << "Cat default constructor called" << std::endl;
	return ;
}

Cat::Cat(const Cat &src)
{
	*this = src;
	std::cout << "Cat copy contructor called" << std::endl;
	return ;
}

// ===== Destructor =====
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

// ===== Operators =====
Cat	&Cat::operator=(const Cat &src)
{
	this->_type = src.getType();
	return (*this);
}

// ===== Methods =====
int	Cat::makeSound(void) const
{
	std::cout << "meow~" << std::endl;
	return (0);
}