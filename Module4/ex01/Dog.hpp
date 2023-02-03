#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

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
	void		printIdeas(void) const;

private:
	// ===== Attributes =====
	Brain	*_brain;
};

#endif