#include "Dog.hpp"

// ===== Constructors =====
Dog::Dog() : _brain(new Brain())
{
	this->setType("Dog");
	std::cout << "Dog default constructor called" << std::endl;
	return ;
}

Dog::Dog(const Dog &src) : _brain(new Brain())
{
	*this = src;
	std::cout << "Dog copy contructor called" << std::endl;
	return ;
}

// ===== Destructor =====
Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

// ===== Operators =====
Dog	&Dog::operator=(const Dog &src)
{
	this->_type = src.getType();
	return (*this);
}

// ===== Methods =====
int	Dog::makeSound(void) const
{
	std::cout << "woof-woof!" << std::endl;
	return (0);
}

void	Dog::printIdeas(void) const
{
	std::string *ideas = this->_brain->getIdeas();
	for (int i = 0; i < 100; i++)
		std::cout << i << ". " << ideas[i] << std::endl;
	delete []ideas;
}