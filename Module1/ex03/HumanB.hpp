#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
public:
	// ===== Contructor =====
	HumanB();
	HumanB(std::string name);

	// ===== Destructor =====
	~HumanB();

	// ===== Setter =====
	void	setWeapon(Weapon &weapon);

	// ===== Method =====
	void	attack(void);

private:
	// ===== Variables =====
	Weapon		*_weapon;
	std::string	_name;
};

#endif