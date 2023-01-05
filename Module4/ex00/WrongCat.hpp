#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	// ===== Constructors =====
	WrongCat();
	WrongCat(const WrongCat &src);

	// ===== Destructor =====
	~WrongCat();

	// ===== Operators =====
	WrongCat	&operator=(const WrongCat &src);

	// ===== Methods =====
	int	makeSound(void) const;
};

#endif