#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include "ClapTrap.hpp"

int	main(void)
{
	// Create ClapTraps paco and pepito
	std::cout << YELLOW << "\nSe crea un ClapTrap paco\n" << RESET << std::endl;
	ClapTrap	paco;
	paco = ClapTrap("paco");

	std::cout << YELLOW << "\nSe crea un ClapTrap pepito\n" << RESET << std::endl;
	ClapTrap	pepito("pepito");
	
	// paco attack
	std::cout << YELLOW << "\nPruebas de paco:\n" << RESET << std::endl;

	std:: cout << "Los puntos de ataque de " << paco.getName() << " son de "
	<< paco.getHitPoints() << " puntos" << std::endl;

	paco.attack("juanito");
	paco.attack("lola");

	std:: cout << "Los puntos de ataque de " << paco.getName() << " son de "
	<< paco.getHitPoints() << " puntos" << std::endl;

	// pepito attack
	std::cout << YELLOW << "\nPruebas de pepito:\n" << RESET << std::endl;

	std:: cout << "Los puntos de energia de " << pepito.getName() << " son de "
	<< pepito.getEnergyPoints() << " puntos" << std::endl;

	pepito.takeDamage(6);

	std:: cout << "Los puntos de energia de " << pepito.getName() << " son de "
	<< pepito.getEnergyPoints() << " puntos" << std::endl;

	pepito.beRepaired(4);

	std:: cout << "Los puntos de energia de " << pepito.getName() << " son de "
	<< pepito.getEnergyPoints() << " puntos" << std::endl;

	std::cout << YELLOW << "\nAcaba el programa\n" << RESET << std::endl;
	return (0);
}