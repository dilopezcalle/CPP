#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream>

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	// Create animal's array
	std::cout << YELLOW << "\nSe crea el array de animales" << RESET << std::endl;
	AAnimal	*animal_array[100];

	// Half of dogs
	std::cout << YELLOW << "\nLa mitad de los animales se crean como perros" << RESET << std::endl;
	for (int i = 0; i < 5; i++)
		animal_array[i] = new Dog();

	// Half of cats
	std::cout << YELLOW << "\nLa mitad de los animales se crean como gatos" << RESET << std::endl;
	for (int i = 5; i < 10; i++)
		animal_array[i] = new Cat();

	// Print animal's type
	std::cout << YELLOW << "\nTipos de los animales" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << animal_array[i]->getType() << std::endl;

	// Free animal's array
	std::cout << YELLOW << "\nSe libera memoria" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
		delete animal_array[i];

	// Instantiating a default class Animal (it's NOT possible)
	// std::cout << YELLOW << "\nInstanciando la clase por defecto Animal"
	// << RESET << std::endl;
	// AAnimal	*animal = new AAnimal();
	// delete animal;

	std::cout << std::endl;
	return (0);
}