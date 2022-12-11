#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
public:

	// ===== Contructor =====
	Zombie();

	// ===== Destructor =====
	~Zombie();

	// ===== Setters =====
	void	setName(std::string name);
	
	// ===== Methods =====
	void	announce(void) const;

private:

	std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif