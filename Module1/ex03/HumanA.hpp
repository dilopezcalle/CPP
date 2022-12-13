#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
public:
	// ===== Contructor =====
	HumanA(std::string name, Weapon &weapon);

	// ===== Destructor =====
	~HumanA();

	// ===== Method =====
	void	attack(void);

private:
	// ===== Variables =====
	Weapon		&_weapon;
	std::string	_name;
};

#endif