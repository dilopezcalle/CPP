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
			this->_arrMateria[i] = arr_materia[i]->clone();
		else
			this->_arrMateria[i] = NULL;
	}

	delete []arr_materia;
	return (*this);
}

// ===== Getters =====
AMateria	**MateriaSource::getArrMaterias(void) const
{
	AMateria	*arr_materia[4];

	for (int i = 0; i < 4; i++)
		arr_materia[i] = this->_arrMateria[i];
	
	return (arr_materia);
}

// ===== Methods =====
void	MateriaSource::learnMateria(AMateria *materia)
{
	int	i;

	for (i = 0; i < 4 && this->_arrMateria[i]; i++);
	if (i > 3)
		return ;

	this->_arrMateria[i] = materia->clone();
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 3 && this->_arrMateria[i]; i++)
		if (type.compare(this->_arrMateria[i]->getType()))
			return (this->_arrMateria[i]->clone());

	return (0);
}