#include <iostream>
#include <cmath>

#include "Fixed.hpp"

// ===== Constructors =====

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int raw) : _rawBits(raw * (1 << this->_fracBits))
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const float raw) : _rawBits(roundf(raw * (1 << this->_fracBits)))
{
	std::cout << "Float constructor called" << std::endl;
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
	return (this->_rawBits);
}

// ===== Setters =====

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
	return ;
}

// ===== Methods =====

int	Fixed::toInt(void) const
{
	return (this->_rawBits / (1 << this->_fracBits));
}

float	Fixed::toFloat(void) const
{
	return ((float)((float)this->_rawBits / (1 << this->_fracBits)));
}

// ===== Operators =====

Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_rawBits = src.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream& os, const Fixed &src)
{
	os << src.toFloat();
	return (os);
}
