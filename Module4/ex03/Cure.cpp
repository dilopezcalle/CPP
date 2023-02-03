#include "Cure.hpp"

// ===== Constructors =====
Cure::Cure()
{
	this->_type = "cure";
	return ;
}

Cure::Cure(const Cure &src)
{
	*this = src;
	return ;
}

// ===== Destructor =====
Cure::~Cure()
{
	return ;
}

// ===== Operators =====
Cure	&Cure::operator=(const Cure &src)
{
	this->_type = src.getType();
	return (*this);
}

// ===== Methods =====
AMateria* Cure::clone() const
{
	AMateria	*newMateria = new Cure(*this);
	return (newMateria);
}
// virtual void use(ICharacter& target);