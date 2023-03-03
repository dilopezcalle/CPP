#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream>

#include "iter.hpp"

template<typename T>
void	function(T const &target)
{
	std::cout << target << std::endl;
	return ;
}

int main( void )
{
	int			int_array[] = {1, 2, 3};
	std::string	string_array[] = {"hola", "buenas", "tardes"};

	std::cout << YELLOW << "\nFunction template con un array de enteros:" << RESET << std::endl;
	::iter(int_array, 3, function);
	std::cout << YELLOW << "\nFunction template con un array de strings:" << RESET << std::endl;
	::iter(string_array, 3, function);
	return (0);
}

