#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
public:
	// ===== Constructors =====
	AMateria();
	AMateria(const AMateria &src);
	AMateria(std::string const & type);

	// ===== Destructor =====
	virtual ~AMateria();

	// ===== Operators =====
	AMateria	&operator=(const AMateria &src);

	// ===== Getters =====
	std::string const &getType() const;

	// ===== Methods =====
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:
	std::string	_type;
};

#endif