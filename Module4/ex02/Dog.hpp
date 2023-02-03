#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
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