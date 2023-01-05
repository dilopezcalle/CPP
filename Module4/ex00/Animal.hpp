#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
public:
	// ===== Constructors =====
	Animal();
	Animal(const Animal &src);

	// ===== Destructor =====
	~Animal();

	// ===== Operators =====
	Animal	&operator=(const Animal &src);

	// ===== Getters =====
	std::string	getType(void) const;

	// ===== Setters =====
	void	setType(std::string type);

	// ===== Methods =====
	virtual int	makeSound(void) const;

protected:
	// ===== Attributes =====
	std::string	_type;
};

#endif