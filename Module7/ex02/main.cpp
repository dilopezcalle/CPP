#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream>

#include "Array.hpp"

int main( void )
{
	Array<int> 			num_array(5);
	Array<std::string>	string_array(3);

	std::cout << YELLOW << "\nPruebas con excepciones" << RESET << std::endl;
	try
	{
		num_array[-1] = 1;
	}
	catch(std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		num_array[6] = 1;
	}
	catch(std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << YELLOW << "\nTest de array de enteros" << RESET << std::endl;
	try
	{
		for (unsigned int i = 1; i <= num_array.size(); i++)
			num_array[i - 1] = i;
		for (unsigned int i = 0; i < num_array.size(); i++)
			std::cout << num_array[i] << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << YELLOW << "\nTest de array de strings" << RESET << std::endl;
	try
	{
		string_array[0] = "Hola";
		string_array[1] = "Buenas";
		string_array[2] = "Tardes";
		for (unsigned int i = 0; i < string_array.size(); i++)
			std::cout << string_array[i] << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	return (0);
}
