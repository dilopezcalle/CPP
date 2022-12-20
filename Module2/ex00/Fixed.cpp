#include <iostream>

#include "Fixed.hpp"

// ===== Contructors =====

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_rawBits = 0;
	return ;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

// ===== Destructor =====

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

// ===== Getters =====

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

// ===== Setters =====

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
	return ;
}

// ===== Operators =====

Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_rawBits = src.getRawBits();
	return (*this);
}
