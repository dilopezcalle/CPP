#include "Brain.hpp"

// ===== Constructors =====
Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	return ;
}

Brain::Brain(const Brain &src)
{
	*this = src;
	std::cout << "Animal copy constructor called" << std::endl;
	return ;
}

// ===== Destructor =====
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

// ===== Operators =====
Brain	&Brain::operator=(const Brain &src)
{
	std::string	*ideas = src.getIdeas();
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = ideas[i];
	delete []ideas;
	return (*this);
}

// ===== Getters =====
std::string	*Brain::getIdeas(void) const
{
	std::string	*ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		ideas[i] = this->_ideas[i];
	return (ideas);
}

// ===== Setters =====
void	Brain::setIdeas(std::string ideas[100])
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = ideas[i];
	return ;
}