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
	int		toInt(void) const;
	float	toFloat(void) const;
	Fixed	&operator=(const Fixed &src);

private:
	// ===== Variables =====
	int					_rawBits;
	const static int	_fracBits = 8;
};

std::ostream	&operator<<(std::ostream& os, const Fixed &src);

#endif