#include <iostream>

class Weapon
{
public:
	// ===== Contructor =====
	Weapon();

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