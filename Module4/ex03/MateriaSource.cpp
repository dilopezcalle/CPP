#include "MateriaSource.hpp"

#include "Ice.hpp"
#include "Cure.hpp"

// ===== Constructors =====
MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_arrMateria[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = src;
	return ;
}

// ===== Destructor =====
MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4 && this->_arrMateria[i]; i++)
		delete this->_arrMateria[i];
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
	std::cout << "MateriaSource learns " << materia->getType() << std::endl;
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 3 && this->_arrMateria[i]; i++)
		if (this->_arrMateria[i] && type.compare(this->_arrMateria[i]->getType()) == 0)
		{
			std::cout << "MateriaSource creates " << this->_arrMateria[i]->getType() << std::endl;
			return (this->_arrMateria[i]->clone());
		}

	return (0);
}