#include "Character.hpp"

// ===== Constructors =====
Character::Character() : _name("NULL")
{
	for (int i = 0; i < 4; i++)
		this->_slot[i] = NULL;
	return ;
}
Character::Character(const Character &src)
{
	*this = src;
	return ;
}
Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_slot[i] = NULL;
	return ;
}

// ===== Destructor =====
Character::~Character()
{
	for (int i = 0; i < 4 && this->_slot[i]; i++)
		delete this->_slot[i];
	return ;
}

// ===== Operators =====
Character	&Character::operator=(const Character &src)
{
	AMateria	**slot = src.getSlot();

	for (int i = 0; i < 4; i++)
	{
		if (slot[i])
			this->_slot[i] = slot[i];
		else
			this->_slot[i] = NULL;
	}

	this->_name = src.getName();

	// delete []slot;
	return (*this);
}

// ===== Getters =====
std::string const &Character::getName() const
{
	return (this->_name);
}

AMateria	**Character::getSlot(void) const
{
	AMateria	**slot = NULL;

	for (int i = 0; i < 4; i++)
		slot[i] = this->_slot[i]->clone();
	
	return (slot);
}

// ===== Methods =====
void Character::equip(AMateria* m)
{
	int	i;

	for (i = 0; i < 4 && this->_slot[i]; i++);
	if (i == 4)
		return ;

	this->_slot[i] = m;
	return ;
}
void Character::unequip(int idx)
{
	if (idx > 3)
		return ;
	if (this->_slot[idx])
		return ;

	// delete this->_slot[idx]; // FORBIDDEN
	this->_slot[idx] = NULL;
}
void Character::use(int idx, ICharacter& target)
{
	if (idx > 3)
		return ;
	if (!this->_slot[idx])
		return ;

	this->_slot[idx]->use(target);
	delete this->_slot[idx];
	this->_slot[idx] = NULL;
}

int	Character::test(void)
{
	if (!this->_slot[0])
		std::cout << "hola" << std::endl;

	return (0);
}