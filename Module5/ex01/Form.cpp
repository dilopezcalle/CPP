#include "Form.hpp"

// ===== Constructors =====
Form::Form() :
_name("NULL"), _isSigned(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << "Form default constructor called" << std::endl;
	return;
}
Form::Form(const Form &src) :
_name(src.getName()), _isSigned(src.getIsSigned()),
_gradeSign(src.getGradeSign()), _gradeExec(src.getGradeExec())
{
	std::cout << "Form copy constructor called" << std::endl;
	return;
}
Form::Form(std::string name, int gradeSign, int gradeExec) : 
_name(name), _isSigned(false),
_gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();

	std::cout << "Form constructor called" << std::endl;

	return ;
}

// ===== Destructor =====
Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
	return ;
}

// ===== Operators =====
Form &Form::operator=(const Form &src)
{
	this->_isSigned = src.getIsSigned();
	return (*this);
}

// ===== Getters =====
const std::string Form::getName(void) const
{
	return (this->_name);
}
bool Form::getIsSigned(void) const
{
	return (this->_isSigned);
}
int Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}
int Form::getGradeExec(void) const
{
	return (this->_gradeExec);
}

// ===== Methods =====
int Form::beSigned(const Bureaucrat &src)
{
	if (src.getRange() > this->_gradeSign)
		throw Form::GradeTooLowException();

	if (this->_isSigned == true)
		return (1);
	this->_isSigned = true;
	return (0);
}

std::ostream	&operator<<(std::ostream &os, const Form &src)
{
	os << src.getName() << ", gradeSign is " << src.getGradeSign()
	<< " and gradeExec is " << src.getGradeExec();
	return (os);
}