#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	// ===== Constructors =====
	FragTrap();
	FragTrap(const FragTrap &src);
	FragTrap(std::string name);

	// ===== Destructor ======
	~FragTrap();

	// ===== Operators =====
	FragTrap	&operator=(const FragTrap &src);

	// ===== Methods =====
	void highFivesGuys(void);
};

#endif