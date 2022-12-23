#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);
Fixed	calculate_distance(Point const p1, Point const p2);
Fixed	square_root(Fixed num);
Fixed	absolute_value(Fixed num);

int main( void )
{
	Point	a(Fixed(1), Fixed(1));
	Point	b(Fixed(10), Fixed(1));
	Point	c(Fixed(1), Fixed(10));
	Point	point(Fixed(8), Fixed(2));
	
	if (bsp(a, b, c, point))
		std::cout << "Está dentro" << std::endl;
	else
		std::cout << "Está fuera" << std::endl;
	return 0;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	sideAB = calculate_distance(a, b);
	Fixed	sideAC = calculate_distance(a, c);
	Fixed	sideBC = calculate_distance(b, c);
	Fixed	shorterSide;

	if (sideAB < sideAC)
		shorterSide = sideAB;
	else
		shorterSide = sideAC;
	if (shorterSide > sideBC)
		shorterSide = sideBC;
		
	Fixed	sidePA = calculate_distance(point, a);
	Fixed	sidePB = calculate_distance(point, b);
	Fixed	sidePC = calculate_distance(point, c);
	std::cout << "src1: " << sidePC << std::endl;
	std::cout << "src2: " << shorterSide << std::endl;
	if (sidePA < shorterSide && sidePB < shorterSide && sidePC < shorterSide)
		return (true);
	return (false);
}

Fixed	calculate_distance(Point const p1, Point const p2)
{
	Fixed	distance_x;
	Fixed	distance_y;
	Fixed	distance;

	distance_x = absolute_value(p1.getX() - p2.getX());
	distance_x = distance_x * distance_x;
	distance_y = absolute_value(p1.getY() - p2.getY());
	distance_y = distance_y * distance_y;
	distance = square_root(distance_x + distance_y);
	return (distance);
}

Fixed	square_root(Fixed num)
{
	Fixed	res, i;
	Fixed	estimate(0.01f);

	num = absolute_value(num);
	do
	{
		i = i + estimate;
		res = i * i;
	} while (num >= res + estimate);
	return (i);
}

Fixed	absolute_value(Fixed num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}