#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream>

#include "span.hpp"

int	main(void)
{
	try
	{
		std::cout << YELLOW << "\nSe genera un Span con números random"
		<< RESET << std::endl;
		Span	span(10000);

		span.generateNewSpan(5);
		span.printSpan();
		std::cout << "Distancia más corta: " << span.shortestSpan() << std::endl;
		std::cout << "Distancia más larga: " << span.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Span sp = Span(5);
	try
	{
		std::cout << YELLOW<< "\nSe crea una Span con estos números y se prueba los métodos:"
		<< RESET << std::endl;
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.printSpan();
		std::cout << "Distancia más corta: " << sp.shortestSpan() << std::endl;
		std::cout << "Distancia más larga: " << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << YELLOW << "\nSe crea un Span a partir del anterior:"
		<< RESET << std::endl;
		Span copy(sp);
		sp.printSpan();
		std::cout << "Distancia más corta: " << sp.shortestSpan() << std::endl;
		std::cout << "Distancia más larga: " << sp.longestSpan() << std::endl;

		std::cout << "\nExcepción en caso de que el Span esté lleno: " << RED;
		copy.addNumber(10);
		std::cout << RESET;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << YELLOW << "\nSe crea un Span con 2 huecos y se agrega UN solo número:"
		<< RESET << std::endl;
		Span span(2);

		span.addNumber(10);
		span.printSpan();

		std::cout << "Excepción si se intenta llamar un método pero no se tienen sufientes números: ";
		std::cout << RED << span.shortestSpan() << RESET << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}