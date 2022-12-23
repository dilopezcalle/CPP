#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream>

#include "Fixed.hpp"

int main( void )
{
	std::cout << YELLOW << "\nSe crea Fixed a con valor inicial 0\n" << RESET << std::endl;
	Fixed a;
	
	a = 4;
	a = (a * 4) - 1;
	a = (a / 3) + 2;
	std::cout << "a es " << a << std::endl;

	std::cout << YELLOW << "\nSe crea Fixed b con valor inicial 5.05 * 2\n" << RESET << std::endl;
	Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << b << std::endl;
	std::cout << ++b << std::endl;
	std::cout << b << std::endl;
	std::cout << b++ << std::endl;
	std::cout << b << std::endl;

	std::cout << YELLOW << "\nSe crea const Fixed c con valor inicial igual: b + 2\n"
	<< RESET << std::endl;
	Fixed const	c(b + 2);
	std::cout << "c es " << c << std::endl;

	std::cout << YELLOW << "\nMáximo entre a y b: " << RESET;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << YELLOW << "Mínimo entre a y b: " << RESET;
	std::cout << Fixed::min( a, b ) << std::endl;

	std::cout << YELLOW << "Máximo entre a y c: " << RESET;
	std::cout << Fixed::max( a, c ) << std::endl;

	std::cout << YELLOW << "Mínimo entre a y c: " << RESET;
	std::cout << Fixed::min( a, c ) << std::endl;

	std::cout << YELLOW << "\nAcaba el programa" << RESET << std::endl;
	return 0;
}