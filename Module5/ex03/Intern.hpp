#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{
public:
	// ===== Constructors =====
	Intern();
	Intern(const Intern &src);

	// ===== Destructor =====
	~Intern();

	// ===== Operators =====
	Intern	&operator=(const Intern &src);

	// ===== Methods =====
	AForm	*makeForm(const std::string name, const std::string target);
};

#endif