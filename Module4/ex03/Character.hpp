#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	// ===== Constructors =====
	Character();
	Character(const Character &src);
	Character(std::string name);

	// ===== Destructor =====
	~Character();

	// ===== Operators =====
	Character	&operator=(const Character &src);

	// ===== Getters =====
	virtual std::string const &getName() const;
	AMateria	**getSlot(void) const;

	// ===== Methods =====
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
	int	test(void);

private:
	std::string	_name;
	AMateria	*_slot[4];
};

#endif