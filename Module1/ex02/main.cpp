#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream>

int	main(void)
{
	// Create string variable, pointer and reference
	std::cout << GREEN << "\nSe crea str = 'HI THIS IS BRAIN', se le crea un puntero y referencia\n" 
	<< RESET << std::endl;
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	// Print str's address from variable, pointer and reference
	std::cout << YELLOW << "Address from string:\t" << RESET << &str << std::endl;
	std::cout << YELLOW << "Address from pointer:\t" << RESET << stringPTR << std::endl;
	std::cout << YELLOW << "Address from reference:\t" << RESET << &stringREF << std::endl;

	std::cout << std::endl;

	// Print str's value from variable, pointer and reference
	std::cout << YELLOW << "Value from string:\t" << RESET << str << std::endl;
	std::cout << YELLOW << "Value from pointer:\t" << RESET << *stringPTR << std::endl;
	std::cout << YELLOW << "Value from reference:\t" << RESET << stringREF << std::endl;

	std::cout << std::endl;
	return (0);
}