#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream> 
#include "data.hpp"

int	main(int argc, char **argv)
{
	// Create a data struct
	std::cout << YELLOW << "\nSe crea una estructura" << RESET << std::endl;
	Data		ptr;
	ptr.name = "book";
	ptr.size = 43;
	std::cout << "Nombre: " << ptr.name << "\nTamaño: " << ptr.size << std::endl;

	// Serialize data struct
	std::cout << YELLOW 
	<< "\nSe serializa la estructura y se comparan las direcciones de memoria"
	<< RESET << std::endl;
	uintptr_t	raw;
	raw = serialize(&ptr);
	std::cout << "SIN serializar:\t" << &ptr << "\nSerializado:\t" << &raw << std::endl;

	// Deserialize data struct
	std::cout << YELLOW 
	<< "\nSe deserializa la estructura y se comparan las direcciones de memoria"
	<< RESET << std::endl;
	Data	*data;
	data = deserialize(raw);
	std::cout << "SIN deserializar:\t" << &raw << "\nDeserializado:\t\t" << data << std::endl;

	std::cout << YELLOW << "\nEstructura deserializada" << RESET << std::endl;
	std::cout << "Nombre: " << data->name << "\nTamaño: " << data->size << std::endl;
}