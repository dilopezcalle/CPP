
#include <iostream>
#include <cctype>

static int	str_to_upper(char *str);

int	main(int argn, char *argv[])
{
	if (argn < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; argv[i]; i++)
		str_to_upper(argv[i]);
	std::cout << std::endl;
	return (0);
}

static int	str_to_upper(char *str)
{
	for (int i = 0; str[i] != 0; i++)
		std::cout << (char)toupper(str[i]);
	return (0);
}