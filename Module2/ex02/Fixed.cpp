#include <iostream>
#include <cmath>

#include "Fixed.hpp"

// ===== Constructors =====

Fixed::Fixed() : _rawBits(0)
{
	return ;
}

Fixed::Fixed(const int raw) : _rawBits(raw * (1 << this->_fracBits))
{
	return ;
}

Fixed::Fixed(const float raw) : _rawBits(roundf(raw * (1 << this->_fracBits)))
{
	return ;
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
	return ;
}

// ===== Destructor =====
Fixed::~Fixed()
{
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

Fixed	&Fixed::min(Fixed &src1, Fixed &src2)
{
	if (src1 <= src2)
		return (src1);
	else
		return (src2);
}

Fixed	&Fixed::max(Fixed &src1, Fixed &src2)
{
	if (src1 >= src2)
		return (src1);
	else
		return (src2);
}

const Fixed	&Fixed::min(const Fixed &src1, const Fixed &src2)
{
	if (src1 <= src2)
		return (src1);
	else
		return (src2);
}

const Fixed	&Fixed::max(const Fixed &src1, const Fixed &src2)
{
	if (src1 >= src2)
		return (src1);
	else
		return (src2);
}

// ===== Operators =====

Fixed	&Fixed::operator=(const Fixed &src)
{
	this->_rawBits = src.getRawBits();
	return (*this);
}

Fixed	&Fixed::operator+(const Fixed &src)
{
	this->setRawBits(this->_rawBits + src.getRawBits());
	return (*this);
}

Fixed	&Fixed::operator-(const Fixed &src)
{
	this->setRawBits(this->_rawBits - src.getRawBits());
	return (*this);
}

Fixed	&Fixed::operator*(const Fixed &src)
{
	this->setRawBits(this->_rawBits * src.toFloat());
	return (*this);
}

Fixed	&Fixed::operator/(const Fixed &src)
{
	this->setRawBits(this->_rawBits / src.toFloat());
	return (*this);
}

Fixed	&Fixed::operator++(void)
{
	this->setRawBits(this->_rawBits + 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);

	this->setRawBits(this->_rawBits + 1);
	return (old);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->_rawBits - 1);
	return (*this);
}

Fixed	&Fixed::operator--(int)
{
	this->setRawBits(this->_rawBits - 1);
	return (*this);
}

// ==========

std::ostream	&operator<<(std::ostream& os, const Fixed &src)
{
	os << src.toFloat();
	return (os);
}

// ===== Arithmetic operators =====

bool	operator>(const Fixed &src1, const Fixed &src2)
{
	if (src1.getRawBits() > src2.getRawBits())
		return (1);
	else
		return (0);
}

bool	operator<(const Fixed &src1, const Fixed &src2)
{
	if (src1.getRawBits() < src2.getRawBits())
		return (1);
	else
		return (0);
}

bool	operator>=(const Fixed &src1, const Fixed &src2)
{
	if (src1.getRawBits() >= src2.getRawBits())
		return (1);
	else
		return (0);
}

bool	operator<=(const Fixed &src1, const Fixed &src2)
{
	if (src1.getRawBits() <= src2.getRawBits())
		return (1);
	else
		return (0);
}

bool	operator==(const Fixed &src1, const Fixed &src2)
{
	if (src1.getRawBits() == src2.getRawBits())
		return (1);
	else
		return (0);
}

bool	operator!=(const Fixed &src1, const Fixed &src2)
{
	if (src1.getRawBits() != src2.getRawBits())
		return (1);
	else
		return (0);
}
