#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream>

#include "Fixed.hpp"

int main(void)
{
	std::cout << YELLOW << "\nSe crean 3 variables Fixed a, b y c\n" << RESET << std::endl;
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << YELLOW << "\nSe obtinen los valores de punto entero\n" << RESET <<std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << YELLOW << "\nAcaba el programa\n" << RESET << std::endl;
	return 0;
}