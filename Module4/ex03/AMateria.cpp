#include "AMateria.hpp"

// ===== Constructors =====
AMateria::AMateria() : _type("NULL")
{
	return ;
}

AMateria::AMateria(const AMateria &src)
{
	*this = src;
	return ;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	return ;
}

// ===== Destructor =====
AMateria::~AMateria()
{
	return ;
}

// ===== Operators =====
AMateria	&AMateria::operator=(const AMateria &src)
{
	this->_type = src.getType();
	return (*this);
}

// ===== Getters =====
std::string const &AMateria::getType() const
{
	return (this->_type);
}

// ===== Methods =====
void AMateria::use(ICharacter& target)
{

}