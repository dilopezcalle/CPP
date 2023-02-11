#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream>

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	// Creating Animals
	std::cout << YELLOW << "\nSe crea un animal" << RESET << std::endl;
	const Animal *animal = new Animal();
	std::cout << YELLOW << "\nSe crea un perro" << RESET << std::endl;
	const Animal *dog = new Dog();
	std::cout << YELLOW << "\nSe crea un gato" << RESET << std::endl;
	const Animal *cat = new Cat();

	// Print animal type
	std::cout << YELLOW << "\nTipo del animal" << RESET << std::endl;
	std::cout << GREEN << "Perro: " << RESET
	<< dog->getType() << " " << std::endl;
	std::cout << GREEN << "Gato: " << RESET
	<< cat->getType() << " " << std::endl;

	// Print sounds
	std::cout << YELLOW << "\nSonido del animal" << RESET << std::endl;
	std::cout << GREEN << "Perro: " << RESET;
	dog->makeSound();
	std::cout << GREEN << "Gato: " << RESET;
	cat->makeSound();
	std::cout << GREEN << "Animal: " << RESET;
	animal->makeSound();

	// Free animals
	std::cout << YELLOW << "\nSe liberan los animales" << RESET << std::endl;
	delete animal;
	delete dog;
	delete cat;

	// ===== Wrong animals =====
	std::cout << RED << "\n===== Casos erróneos =====" << RESET << std::endl;

	// Create wrong animals
	std::cout << YELLOW << "\nSe crea un animal erróneo" << RESET << std::endl;
	const WrongAnimal* wrong_animal = new WrongAnimal();
	std::cout << YELLOW << "\nSe crea un gato erróneo" << RESET << std::endl;
	const WrongAnimal* wrong_cat = new WrongCat();

	std::cout << GREEN << "\nTipo del gato erróneo: " << RESET
	<< wrong_cat->getType() << " " << std::endl;
	
	std::cout << YELLOW << "\nSonido del animal erróneo" << RESET << std::endl;
	std::cout << GREEN << "Gato: " << RESET;
	wrong_cat->makeSound();
	std::cout << GREEN << "Animal: " << RESET;
	wrong_animal->makeSound();

	// Create cat as cat
	std::cout << YELLOW << "\nSe crea un gato erróneo como gato y no como animal" << RESET << std::endl;
	const WrongCat* cat_cat = new WrongCat();
	cat_cat->makeSound();

	// Free wrong animals
	std::cout << YELLOW << "\nSe liberan los animales erróneos" << RESET << std::endl;
	delete wrong_animal;
	delete wrong_cat;
	delete cat_cat;

	return (0);
}