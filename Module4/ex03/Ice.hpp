#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	// ===== Constructors =====
	Ice();
	Ice(const Ice &src);

	// ===== Destructor =====
	~Ice();
	
	// ===== Operators =====
	Ice	&operator=(const Ice &src);

	// ===== Methods =====
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);

private:

};

#endif