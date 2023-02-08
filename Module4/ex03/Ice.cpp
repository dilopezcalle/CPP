#include "Ice.hpp"

// ===== Constructors =====
Ice::Ice()
{
	this->_type = "ice";
	return ;
}

Ice::Ice(const Ice &src)
{
	*this = src;
	return ;
}

// ===== Destructor =====
Ice::~Ice()
{
	return ;
}

// ===== Operators =====
Ice	&Ice::operator=(const Ice &src)
{
	this->_type = src.getType();
	return (*this);
}

// ===== Methods =====
AMateria* Ice::clone() const
{
	AMateria	*newMateria = new Ice(*this);
	return (newMateria);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}