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
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);

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
			std::cout << "Se encontró el número " << *it << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << YELLOW << "\nPrueba con elemento que no está en lista" << RESET << std::endl;
		try
		{
			std::vector<int>::iterator	it = easyfind(vec, -4);
			std::cout << "Se encontró el número " << *it << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::list<int>	list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(42);
		list.push_back(4);
		list.push_back(5);
		std::list<int>::iterator	begin = list.begin();
		std::cout << GREEN << "\nLISTA:" << RESET << std::endl;
		while (begin != list.end())
		{
			std::cout << *begin << ", ";
			begin++;
		}
		std::cout << std::endl;
		std::cout << YELLOW << "\nPrueba con elemento de la lista (3)" << RESET << std::endl;
		try
		{
			std::list<int>::iterator	it = easyfind(list, 42);
			std::cout << "Se encontró el número " << *it << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << YELLOW << "\nPrueba con elemento que no está en lista" << RESET << std::endl;
		try
		{
			std::list<int>::iterator	it = easyfind(list, -4);
			std::cout << "Se encontró el número " << *it << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	return (0);
}