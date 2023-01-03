#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	// ===== Constructors =====
	ScavTrap();
	ScavTrap(const ScavTrap &src);
	ScavTrap(std::string name);

	// ===== Destructor =====
	~ScavTrap();

	// ===== Operators =====
	ScavTrap	&operator=(const ScavTrap &src);

	// ===== Methods =====
	void	attack(std::string const &target);
	void	guardGate();
};

#endif