#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream>

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	// Create and add materia in MateriaSource
	std::cout << YELLOW << "\nSe crea una plantilla con las materias Ice y Cure" << RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Create and equip character
	std::cout << YELLOW << "\nSe crea un personaje1 y se le equipa un Ice y un Cure" << RESET << std::endl;
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	// Create other character and use materias
	std::cout << YELLOW << "\nSe crea un personaje2, personaje1 usará materias sobre él" << RESET << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	// Free memory
	std::cout << YELLOW << "\nSe libera la memoria correspondiente" << RESET << std::endl;
	delete bob;
	delete me;
	delete src;

	return 0;

}