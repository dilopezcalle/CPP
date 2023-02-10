#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
public:
	// ===== Constructors =====
	WrongAnimal();
	WrongAnimal(const WrongAnimal &src);

	// ===== Destructor =====
	virtual ~WrongAnimal();

	// ===== Operators =====
	WrongAnimal	&operator=(const WrongAnimal &src);

	// ===== Getters =====
	std::string	getType(void) const;

	// ===== Setters =====
	void	setType(std::string type);

	// ===== Methods =====
	int	makeSound(void) const;

protected:
	// ===== Attributes =====
	std::string	_type;
};

#endif