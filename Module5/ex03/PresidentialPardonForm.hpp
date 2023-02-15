#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	// ===== Attributes =====
	std::string	_target;

public:
	// ===== Constructors =====
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm(std::string target);

	// ===== Destructor =====
	~PresidentialPardonForm();

	// ===== Operators =====
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &src);

	// ===== Getters =====
	std::string	getTarget(void) const;

	// ===== Methods =====
	virtual int	execute(const Bureaucrat &executor) const;
};

#endif