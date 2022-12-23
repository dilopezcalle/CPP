#include "Point.hpp"

// ===== Constructors =====

Point::Point() : _x(0), _y(0)
{
	return ;
}

Point::Point(const Point &src) : _x(src.getX()), _y(src.getY())
{
	return ;
}

Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y)
{
	return ;
}

// ===== Destructor =====

Point::~Point()
{
	return ;
}

// ===== Getters =====

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}