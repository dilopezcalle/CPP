#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
public:
	// ===== Constructors =====
	Cat();
	Cat(const Cat &src);

	// ===== Destructor =====
	~Cat();

	// ===== Operators =====
	Cat	&operator=(const Cat &src);

	// ===== Methods =====
	virtual int	makeSound(void) const;

private:
	// ===== Attributes =====
	Brain	*_brain;
};

#endif