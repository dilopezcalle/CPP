#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

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
	Point	point(Fixed(9), Fixed(2));

	std::cout << YELLOW << "\nVértices del triangulo:\n" << RESET << std::endl;
	std::cout << "Vértice A ( " << a.getX() << " , " << a.getY() << " )" << std::endl;
	std::cout << "Vértice B ( " << b.getX() << " , " << b.getY() << " )" << std::endl;
	std::cout << "Vértice C ( " << c.getX() << " , " << c.getY() << " )" << std::endl;
	std::cout << YELLOW << "\nPunto a analizar: " << RESET << "( " << point.getX() << " , " << point.getY() << " )" << std::endl;
	if (bsp(a, b, c, point))
		std::cout << GREEN << "\nEstá dentro\n" << RESET << std::endl;
	else
		std::cout << RED << "\nEstá fuera\n" << RESET << std::endl;
	return 0;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	// PA x PB
	Fixed	result1 = ((a.getX() - point.getX()) * (b.getY() - point.getY())) - ((b.getX() - point.getX()) * (a.getY() - point.getY()));

	// PB x PC
	Fixed	result2 = ((b.getX() - point.getX()) * (c.getY() - point.getY())) - ((c.getX() - point.getX()) * (b.getY() - point.getY()));

	// PC x PA
	Fixed	result3 = ((c.getX() - point.getX()) * (a.getY() - point.getY())) - ((a.getX() - point.getX()) * (c.getY() - point.getY()));

	if (result1 >= 0 && result2 >= 0 && result3 >= 0)
		return (true);
	return (false);
}