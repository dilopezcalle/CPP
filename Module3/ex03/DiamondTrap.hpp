#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	// ===== Constructors =====
	DiamondTrap();
	DiamondTrap(const DiamondTrap &src);
	DiamondTrap(std::string name);

	// ===== Destructor =====
	~DiamondTrap();

	// ===== Operators =====
	DiamondTrap	&operator=(const DiamondTrap &src);

	// ===== Getters =====
	std::string	getDiamondName(void) const;

	// ===== Methods =====
	void	whoAmI(void);

private:
	// ===== Variables =====
	std::string	_name;
};

#endif