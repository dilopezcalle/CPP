#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	// Create ClapTraps paco and pepito
	std::cout << YELLOW << "\nSe crea un ClapTrap paco\n" << RESET << std::endl;
	ClapTrap	paco;
	paco = ClapTrap("paco");

	std::cout << YELLOW << "\nSe crea un ScavTrap pepito\n" << RESET << std::endl;
	ScavTrap 	pepito;
	pepito = ScavTrap("pepito");

	std::cout << YELLOW << "\nSe crea un FragTrap lupita\n" << RESET << std::endl;
	FragTrap 	lupita;
	lupita = FragTrap("lupita");

	std::cout << YELLOW << "\nSe crea un DiamondTrap diego\n" << RESET << std::endl;
	DiamondTrap 	diego;
	diego = DiamondTrap("diego");

	// Display status
	std::cout << YELLOW << "\nStatus\n" << RESET << std::endl;
	paco.displayStatus();
	std::cout << std::endl;
	pepito.displayStatus();
	std::cout << std::endl;
	lupita.displayStatus();
	std::cout << std::endl;
	diego.displayStatus();
	std::cout << GREEN;
	diego.whoAmI();
	std::cout << RESET;
	
	// ===== paco attack =====
	std::cout << YELLOW << "\nPruebas de " << paco.getName() << ":\n" << RESET << std::endl;

	std:: cout << "Los puntos de ataque de " << paco.getName() << " son de "
	<< paco.getHitPoints() << " puntos" << std::endl;

	paco.attack("juanito");
	paco.attack("lola");

	std::cout << "Los puntos de ataque de " << paco.getName() << " son de "
	<< paco.getHitPoints() << " puntos" << std::endl;

	// ===== pepito attack =====
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

	// paco and lupita can't enter in Gate keeper mode because they're not a ScavTrap
	// paco.guardGate();
	// lupita.guardGate();

	// ===== lupita attack =====
	std::cout << YELLOW << "\nPruebas de " << lupita.getName() << ":\n" << RESET << std::endl;

	std::cout << "Los puntos de energia de " << lupita.getName() << " son de "
	<< lupita.getEnergyPoints() << " puntos" << std::endl;

	lupita.attack("juanito");
	lupita.takeDamage(6);

	std::cout << "Los puntos de energia de " << lupita.getName() << " son de "
	<< lupita.getEnergyPoints() << " puntos" << std::endl;

	lupita.beRepaired(4);

	std::cout << "Los puntos de energia de " << lupita.getName() << " son de "
	<< lupita.getEnergyPoints() << " puntos" << std::endl;

	// lupita high five request
	std::cout << YELLOW << "\nPruebas del FragTrap "
	<< lupita.getName() << "\n" << RESET << std::endl;
	lupita.highFivesGuys();

	// paco and pepito can't request high fives because they're not a FragTrap
	// paco.highFivesGuys();
	// pepito.highFivesGuys();

	// pepito Gate keeper mode
	std::cout << YELLOW << "\nPruebas del ScavTrap "
	<< pepito.getName() << "\n" << RESET << std::endl;
	pepito.guardGate();

	// diego tests
	std::cout << YELLOW << "\nPruebas de " << diego.getName() << ":\n" << RESET << std::endl;

	std::cout << "Los puntos de energia de " << diego.getName() << " son de "
	<< diego.getEnergyPoints() << " puntos" << std::endl;

	diego.attack("juanito");
	diego.takeDamage(6);

	std::cout << "Los puntos de energia de " << diego.getName() << " son de "
	<< diego.getEnergyPoints() << " puntos" << std::endl;

	diego.beRepaired(4);

	std::cout << "Los puntos de energia de " << diego.getName() << " son de "
	<< diego.getEnergyPoints() << " puntos" << std::endl;

	std::cout << GREEN;
	diego.highFivesGuys();
	diego.guardGate();
	std::cout << RESET;

	std::cout << YELLOW << "\nAcaba el programa\n" << RESET << std::endl;
	return (0);
}