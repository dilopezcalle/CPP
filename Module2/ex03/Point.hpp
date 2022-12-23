#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
	// ===== Constructor =====
	Point();
	Point(const Point &src);
	Point(const Fixed &x, const Fixed &y);

	// ===== Destructor =====
	~Point();

	// ===== Operators =====
	Point	&operator=(const Point &src);

	// ===== Getters =====
	Fixed	getX(void) const;
	Fixed	getY(void) const;

private:
	// ===== Variables =====
	const Fixed	_x;
	const Fixed	_y;
	
};

#endif