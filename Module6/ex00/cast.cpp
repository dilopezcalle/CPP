#include <iostream>
#include <cstring>
#include <iomanip>
#include <limits>

int	toChar(char *str, int len)
{
	double	num = std::atof(str);

	if ((std::atoi(str) == 0 && (len > 1 || str[0] != '0')) ||
		(num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max()))
		std::cout << "char: impossible" << std::endl;
	else if (num < 32 || num > 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;

	return (0);
}

int	toInt(char *str, int len)
{
	double	num = std::atof(str);

	if ((std::atoi(str) == 0 && (len > 1 || str[0] != '0')) ||
		(num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	return (0);
}

int	toFloat(char *str, int len)
{
	double	num = std::atof(str);

	if (num == 0 && (len > 1 || str[0] != '0'))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1)
		<< static_cast<double>(num) << "f" << std::endl;

	return (0);
}

int	toDouble(char *str, int len)
{
	double	num = std::atof(str);

	if (num == 0 && (len > 1 || str[0] != '0'))
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1)
		<< static_cast<double>(num) << std::endl;

	return (0);
}
