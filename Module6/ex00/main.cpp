#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include "cast.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED << "\nNúmero de argumentos inválido\n" << RESET << std::endl;
		return (0);
	}
	int	len = std::strlen(argv[1]);
	toChar(argv[1], len);
	toInt(argv[1], len);
	toFloat(argv[1], len);
	// toDouble(argv[1], len);
	return (0);
}