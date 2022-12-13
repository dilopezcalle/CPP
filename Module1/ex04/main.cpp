#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream>
#include <fstream>

static int			replace_string_in_file(std::string file, std::string s1, std::string s2);
static std::string	replace_str(std::string line, std::string s1, std::string s2);

int	main(int argn, char *argv[])
{
	// Check number's arguments
	if (argn != 4)
	{
		std::cout << RED << "\nNúmero de argumentos inválidos:\n" << RESET << std::endl;
		std::cout << "1:\t Nombre del fichero" << std::endl;
		std::cout << "2:\t String que desea reemplazar" << std::endl;
		std::cout << "3:\t String sustituto\n" << std::endl;
		return (1);
	}

	// Call replace function
	replace_string_in_file(argv[1], argv[2], argv[3]);

	return (0);
}

static int	replace_string_in_file(std::string file, std::string s1, std::string s2)
{
	// Check access file
	std::ifstream	original(file);
	if (original.is_open() == 0)
	{
		std::cout << RED << "\nNo se puede abrir el fichero '" << file << "'\n" << RESET << std::endl;
		return (1);
	}

	// Open or create file replace
	std::ofstream	new_file;
	new_file.open(file.append(".replace"), std::ofstream::out | std::ofstream::trunc);
	if (new_file.is_open() == 0)
	{
		std::cout << "No se puede abrir o generar el archivo de reemplazo" << std::endl;
		return (1);
	}

	// Check line by line s1
	std::string	content;
	std::string	line;
	do
	{
		line.clear();
		std::getline(original, line);

		// Replace s1 to s2 in line
		content.append(replace_str(line, s1, s2));

		if (original.eof() == 0)
			content.append("\n");
	}
	while (original.eof() == 0);

	new_file << content << std::endl;
	new_file.close();
	original.close();

	std::cout << "\nEl archivo " << GREEN << file
	<< RESET << " se generó correctamente\n" << std::endl;
	return (0);
}

static std::string	replace_str(std::string line, std::string s1, std::string s2)
{
	int	i;
	do
	{
		i = line.find(s1, 0);
		if (i == -1)
			break ;

		// Remove s1 from line
		line.erase(i, s1.length());

		// Insert s2 to line
		line.insert(i, s2);
	}
	while (i > 0);
	return (line);
}