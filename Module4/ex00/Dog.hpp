#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
public:
	// ===== Constructors =====
	Dog();
	Dog(const Dog &src);

	// ===== Destructor =====
	~Dog();

	// ===== Operators =====
	Dog	&operator=(const Dog &src);

	// ===== Methods =====
	virtual int	makeSound(void) const;
};

#endif