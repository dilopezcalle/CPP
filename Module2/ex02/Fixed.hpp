#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	// ===== Contructor =====
	Fixed();
	Fixed(const int raw);
	Fixed(const float raw);
	Fixed(const Fixed &src);

	// ===== Destructor =====
	~Fixed();

	// ===== Getters =====
	int		getRawBits(void) const;

	// ===== Setters =====
	void	setRawBits(int const raw);

	// ===== Methods =====
	int					toInt(void) const;
	float				toFloat(void) const;
	static Fixed		&min(Fixed &src1, Fixed &src2);
	static Fixed		&max(Fixed &src1, Fixed &src2);
	static const Fixed	&min(const Fixed &src1, const Fixed &src2);
	static const Fixed	&max(const Fixed &src1, const Fixed &src2);

	// ===== Comparison operators =====
	Fixed	&operator=(const Fixed &src);
	Fixed	&operator+(const Fixed &src);
	Fixed	&operator-(const Fixed &src);
	Fixed	&operator*(const Fixed &src);
	Fixed	&operator/(const Fixed &src);
	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	&operator--(int);

private:
	// ===== Variables =====
	int					_rawBits;
	const static int	_fracBits = 8;
};

std::ostream	&operator<<(std::ostream& os, const Fixed &src);

// ===== Arithmetic operators =====
bool	operator>(const Fixed &src1, const Fixed &src2);
bool	operator<(const Fixed &src1, const Fixed &src2);
bool	operator>=(const Fixed &src1, const Fixed &src2);
bool	operator<=(const Fixed &src1, const Fixed &src2);
bool	operator==(const Fixed &src1, const Fixed &src2);
bool	operator!=(const Fixed &src1, const Fixed &src2);

#endif