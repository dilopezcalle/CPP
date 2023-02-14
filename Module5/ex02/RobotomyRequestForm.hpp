#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	// ===== Attributes =====
	std::string	_target;

public:
	// ===== Constructors =====
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm(std::string target);

	// ===== Destructor =====
	~RobotomyRequestForm();

	// ===== Operators =====
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &src);

	// ===== Getters =====
	std::string	getTarget(void) const;

	// ===== Methods =====
	virtual int	execute(const Bureaucrat &executor) const;
};

#endif