#include "AForm.hpp"

// ===== Constructors =====
AForm::AForm() :
_name("NULL"), _isSigned(false), _gradeSign(150), _gradeExec(150)
{
	// std::cout << "AForm default constructor called" << std::endl;
	return;
}

AForm::AForm(const AForm &src) :
_name(src.getName()), _isSigned(src.getIsSigned()),
_gradeSign(src.getGradeSign()), _gradeExec(src.getGradeExec())
{
	// std::cout << "AForm copy constructor called" << std::endl;
	return;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : 
_name(name), _isSigned(false),
_gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw AForm::GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw AForm::GradeTooLowException();

	// std::cout << "AForm constructor called" << std::endl;

	return ;
}

// ===== Destructor =====
AForm::~AForm()
{
	// std::cout << "AForm destructor called" << std::endl;
	return ;
}

// ===== Operators =====
AForm &AForm::operator=(const AForm &src)
{
	this->_isSigned = src.getIsSigned();
	return (*this);
}

// ===== Getters =====
const std::string AForm::getName(void) const
{
	return (this->_name);
}
bool AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}
int AForm::getGradeSign(void) const
{
	return (this->_gradeSign);
}
int AForm::getGradeExec(void) const
{
	return (this->_gradeExec);
}

// ===== Setters =====
void	AForm::setIsSigned(bool isSigned)
{
	this->_isSigned = isSigned;
	return ;
}

// ===== Methods =====
int AForm::beSigned(const Bureaucrat &src)
{
	if (src.getRange() > this->_gradeSign)
		throw AForm::GradeTooLowException();

	if (this->_isSigned == true)
		return (1);
	this->_isSigned = true;
	return (0);
}

std::ostream	&operator<<(std::ostream &os, const AForm &src)
{
	os << src.getName() << ", gradeSign is " << src.getGradeSign()
	<< " and gradeExec is " << src.getGradeExec();
	return (os);
}