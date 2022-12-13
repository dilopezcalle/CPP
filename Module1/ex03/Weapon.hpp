#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
public:
	// ===== Contructor =====
	Weapon();
	Weapon(std::string type);

	// ===== Destructor =====
	~Weapon();

	// ===== Getters =====
	std::string	&getType(void);

	// ===== Setter =====
	void	setType(std::string type);

private:
	// ===== Variables =====
	std::string	_type;
};

#endif