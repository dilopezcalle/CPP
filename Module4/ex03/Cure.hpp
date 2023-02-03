#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	// ===== Constructors =====
	Cure();
	Cure(const Cure &src);

	// ===== Destructor =====
	~Cure();
	
	// ===== Operators =====
	Cure	&operator=(const Cure &src);

	// ===== Methods =====
	virtual AMateria* clone() const;
	// virtual void use(ICharacter& target);

private:

};

#endif