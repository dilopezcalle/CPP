#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream>

#include "Fixed.hpp"

int main( void )
{
	std::cout << YELLOW << "\nDeclaración de a:" << RESET << std::endl;
	Fixed a;
	a = Fixed( 1234.4321f );

	std::cout << YELLOW << "\nDeclaración de b:" << RESET << std::endl;
	Fixed const b( 10 );

	std::cout << YELLOW << "\nDeclaración de c:" << RESET << std::endl;
	Fixed const c( 42.42f );

	std::cout << YELLOW << "\nDeclaración de d:" << RESET << std::endl;
	Fixed const d( b );


	std::cout << YELLOW << "\nValores de los Fixed\n" << RESET << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << YELLOW << "\nValores de los Fixed como enteros\n" << RESET << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << YELLOW << "\nValores de los Fixed como enteros\n" << RESET << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;


	std::cout << YELLOW << "\nAcaba el programa\n" << RESET << std::endl;
	return 0;
}