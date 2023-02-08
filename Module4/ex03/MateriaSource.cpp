#include "MateriaSource.hpp"

#include "Ice.hpp"
#include "Cure.hpp"

// ===== Constructors =====
MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_arrMateria[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	*this = src;
	return ;
}

// ===== Destructor =====
MateriaSource::~MateriaSource()
{
	return ;
}

// ===== Operator =====
MateriaSource	&MateriaSource::operator=(const MateriaSource &src)
{
	
	AMateria	**arr_materia = src.getArrMaterias();

	for (int i = 0; i < 4; i++)
	{
		if (arr_materia[i])
			this->_arrMateria[i] = arr_materia[i];
		else
			this->_arrMateria[i] = NULL;
	}

	// delete []arr_materia;
	return (*this);
}

// ===== Getters =====
AMateria	**MateriaSource::getArrMaterias(void) const
{
	AMateria	**arr_materia = NULL;

	for (int i = 0; i < 4; i++)
		arr_materia[i] = this->_arrMateria[i]->clone();

	return (arr_materia);
}

// ===== Methods =====
void	MateriaSource::learnMateria(AMateria *materia)
{
	int	i;

	for (i = 0; i < 4 && this->_arrMateria[i]; i++);
	if (i > 3)
		return ;

	this->_arrMateria[i] = materia;
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 3 && this->_arrMateria[i]; i++)
		if (this->_arrMateria[i] && type.compare(this->_arrMateria[i]->getType()) == 0)
			return (this->_arrMateria[i]->clone());

	return (0);
}