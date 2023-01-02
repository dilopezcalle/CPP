#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	// Create ClapTraps paco and pepito
	std::cout << YELLOW << "\nSe crea un ClapTrap paco\n" << RESET << std::endl;
	ClapTrap	paco;
	paco = ClapTrap("paco");

	std::cout << YELLOW << "\nSe crea un ScavTrap pepito\n" << RESET << std::endl;
	ScavTrap 	pepito;
	pepito = ScavTrap("pepito");

	// Display status
	std::cout << std::endl;
	paco.displayStatus();
	std::cout << std::endl;
	pepito.displayStatus();
	
	// paco attack
	std::cout << YELLOW << "\nPruebas de " << paco.getName() << ":\n" << RESET << std::endl;

	std:: cout << "Los puntos de ataque de " << paco.getName() << " son de "
	<< paco.getHitPoints() << " puntos" << std::endl;

	paco.attack("juanito");
	paco.attack("lola");

	std::cout << "Los puntos de ataque de " << paco.getName() << " son de "
	<< paco.getHitPoints() << " puntos" << std::endl;

	// pepito attack
	std::cout << YELLOW << "\nPruebas de " << pepito.getName() << ":\n" << RESET << std::endl;

	std::cout << "Los puntos de energia de " << pepito.getName() << " son de "
	<< pepito.getEnergyPoints() << " puntos" << std::endl;

	pepito.attack("juanito");
	pepito.takeDamage(6);

	std::cout << "Los puntos de energia de " << pepito.getName() << " son de "
	<< pepito.getEnergyPoints() << " puntos" << std::endl;

	pepito.beRepaired(4);

	std::cout << "Los puntos de energia de " << pepito.getName() << " son de "
	<< pepito.getEnergyPoints() << " puntos" << std::endl;

	// pepito Gate keeper mode
	std::cout << YELLOW << "\nPruebas del ScavTrap "
	<< pepito.getName() << "\n" << RESET << std::endl;
	pepito.guardGate();

	// Paco can't enter in Gate keeper mode because he's not a ScavTrap
	// paco.guardGate();

	std::cout << YELLOW << "\nAcaba el programa\n" << RESET << std::endl;
	return (0);
}