#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	// ===== Constructors =====
	MateriaSource();
	MateriaSource(const MateriaSource &src);


	// ===== Destructor =====
	~MateriaSource();

	// ===== Operator =====
	MateriaSource	&operator=(const MateriaSource &src);

	// ===== Getters =====
	AMateria	**getArrMaterias(void) const;

	// ===== Methods =====
	virtual void		learnMateria(AMateria *materia);
	virtual AMateria*	createMateria(std::string const & type);

private:
	AMateria	*_arrMateria[4];

};

#endif