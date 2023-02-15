#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// ===== Constructors =====
Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
	return ;
}
Intern::Intern(const Intern &src)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
	return ;
}

// ===== Destructor =====
Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
	return ;
}

// ===== Operators =====
Intern	&Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

// ===== Methods =====
AForm	*Intern::makeForm(const std::string name, const std::string target)
{
	std::string	nameForm[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm	*form[3] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target),
	};
	int	i = 0;
	int	j = 0;

	while (i < 3)
	{
		if (name == nameForm[i])
			break ;
		i++;
	}
	while (j < 3)
	{
		if (j != i)
			delete form[j];
		j++;
	}
	if (i == 3)
	{
		std::cout << "Form doesn't exist" << std::endl;
		return (0);
	}
	std::cout << nameForm[i] << " created" << std::endl;
	return (form[i]);
}