#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	// ===== Attributes =====
	std::string	_target;

public:
	// ===== Constructors =====
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm(std::string target);

	// ===== Destructor =====
	~ShrubberyCreationForm();

	// ===== Operators =====
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &src);

	// ===== Getters =====
	std::string	getTarget(void) const;

	// ===== Methods =====
	virtual int	execute(const Bureaucrat &executor) const;
};

#endif