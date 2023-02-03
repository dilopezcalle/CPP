#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
public:
	// ===== Constructors =====
	Brain();
	Brain(const Brain &src);

	// ===== Destructor =====
	~Brain();

	// ===== Operators =====
	Brain	&operator=(const Brain &src);

	// ===== Getters =====
	std::string	*getIdeas(void) const;

	// ===== Setters =====
	void	setIdeas(std::string ideas[10]);

private:
	// ===== Attributes =====
	std::string	_ideas[100];
};

#endif