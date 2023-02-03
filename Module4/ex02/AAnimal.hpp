#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

#include "Brain.hpp"

class AAnimal
{
public:
	// ===== Constructors =====
	AAnimal();
	AAnimal(const AAnimal &src);

	// ===== Destructor =====
	virtual ~AAnimal();

	// ===== Operators =====
	AAnimal	&operator=(const AAnimal &src);

	// ===== Getters =====
	std::string	getType(void) const;

	// ===== Setters =====
	void	setType(std::string type);

	// ===== Methods =====
	virtual int	makeSound(void) const = 0;

protected:
	// ===== Attributes =====
	std::string	_type;
};

#endif