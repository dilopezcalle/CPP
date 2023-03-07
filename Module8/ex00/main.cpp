#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream>
#include <vector>
#include <list>

#include "easyfind.hpp"

int main( void )
{
	{
		std::vector<int> vec{1, 2, 3, 4, 5};

		std::vector<int>::iterator	begin = vec.begin();
		std::cout << GREEN << "\nVECTOR:" << RESET << std::endl;
		while (begin != vec.end())
		{
			std::cout << *begin << ", ";
			begin++;
		}
		std::cout << std::endl;
		std::cout << YELLOW << "\nPrueba con elemento de la lista (2)" << RESET << std::endl;
		try
		{
			std::vector<int>::iterator	it = easyfind(vec, 2);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << YELLOW << "\nPrueba con elemento que no está en lista" << RESET << std::endl;
		try
		{
			std::vector<int>::iterator	it = easyfind(vec, -4);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::list<int>	list = {1, 2, 3, 4, 5};
		std::list<int>::iterator	begin = list.begin();
		std::cout << GREEN << "\nLISTA:" << RESET << std::endl;
		while (begin != list.end())
		{
			std::cout << *begin << ", ";
			begin++;
		}
		std::cout << std::endl;
		std::cout << YELLOW << "\nPrueba con elemento de la lista (2)" << RESET << std::endl;
		try
		{
			std::list<int>::iterator	it = easyfind(list, 2);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << YELLOW << "\nPrueba con elemento que no está en lista" << RESET << std::endl;
		try
		{
			std::list<int>::iterator	it = easyfind(list, -4);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	return (0);
}