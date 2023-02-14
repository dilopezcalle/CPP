#include "PresidentialPardonForm.hpp"

// ===== Constructors =====
PresidentialPardonForm::PresidentialPardonForm() :
AForm("PresidentialPardonForm", 25, 5), _target("NULL")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :
AForm(src.getName(), src.getGradeSign(), src.getGradeExec()), _target(src.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = src;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
	return ;
}

// ===== Destructor =====
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
	return ;
}

// ===== Operators =====
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	this->setIsSigned(src.getIsSigned());
	this->_target = src.getTarget();
	return (*this);
}

// ===== Getters =====
std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

// ===== Methods =====
int	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getRange() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	else if (this->getIsSigned() == false)
		throw AForm::NotSignedException();

	std::cout << this->_target
	<< " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return (0);
}