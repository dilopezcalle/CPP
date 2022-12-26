#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
public:
	// ===== Constructors =====
	ClapTrap();
	ClapTrap(const ClapTrap &src);
	ClapTrap(std::string name);

	// ===== Destructor =====
	~ClapTrap();

	// ===== Operators =====
	ClapTrap	&operator=(const ClapTrap &src);

	// ===== Getters =====
	std::string		getName(void) const;
	unsigned int	getHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getAttackDamage(void) const;

	// ===== Methods =====
	void	attack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private:
	// ===== Variables =====
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
};

#endif