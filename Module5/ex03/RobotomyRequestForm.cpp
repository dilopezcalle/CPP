#include <cstdlib>

#include "RobotomyRequestForm.hpp"

// ===== Constructors =====
RobotomyRequestForm::RobotomyRequestForm() :
AForm("RobotomyRequestForm", 72, 45), _target("NULL")
{
	// std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
AForm(src.getName(), src.getGradeSign(), src.getGradeExec()), _target(src.getTarget())
{
	// std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = src;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	// std::cout << "RobotomyRequestForm constructor called" << std::endl;
	return ;
}

// ===== Destructor =====
RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm destructor called" << std::endl;
	return ;
}

// ===== Operators =====
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	this->setIsSigned(src.getIsSigned());
	this->_target = src.getTarget();
	return (*this);
}

// ===== Getters =====
std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

// ===== Methods =====
int	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getRange() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	else if (this->getIsSigned() == false)
		throw AForm::NotSignedException();

	std::cout << "ZzzZz tAcK-tack- TAck zZZzz..." << std::endl;

	srand(time(NULL));
	int randomNumber = rand();
	if ((randomNumber % 2) == 0)
		std::cout << _target << " was successfully robotized" << std::endl;
	else
		std::cout << _target << " wasn't robotized" << std::endl;
	return (0);
}