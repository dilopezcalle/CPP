#include "Bureaucrat.hpp"

// ===== Constructors =====
Bureaucrat::Bureaucrat() : _name("NULL"), _range(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return ;
}
Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;

	*this = src;
	return ;
}
Bureaucrat::Bureaucrat(std::string name, int range)
{
	std::cout << "Bureaucrat constructor called" << std::endl;

	if (range < 1)
		throw GradeTooHighException();
	else if (range > 150)
		throw GradeTooLowException();

	this->_name = name;
	this->_range = range;

	return ;
}

// ===== Destructor =====
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
	return ;
}

// ===== Operators =====
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	this->_name = src.getName();
	this->_range = src.getRange();
	return (*this);
}

// ===== Getters =====
std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}
int			Bureaucrat::getRange(void) const
{
	return (this->_range);
}

// ===== Methods =====
void	Bureaucrat::incrementRange(void)
{
	if (this->_range - 1 < 1)
		throw GradeTooHighException();

	std::cout << "Grade's " << this->_name << " incremented" << std::endl;
	this->_range--;
	return ;
}
void	Bureaucrat::decrementRange(void)
{
	if (this->_range + 1 > 150)
		throw GradeTooLowException();

	std::cout << "Grade's " << this->_name << " decremented" << std::endl;
	this->_range++;
	return ;
}
int		Bureaucrat::signForm(Form &src)
{
	try
	{
		if (src.beSigned(*this))
			std::cerr << this->_name << " couldn't sign " << src.getName() 
			<< " because form is signed" << std::endl;
		else
			std::cout << this->_name << " signed " << src.getName() << std::endl;
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << this->_name << " couldn't sign " << src.getName()
		<< " because \"" << e.what() << "\"" << std::endl;
	}
	return (0);
}

// ===== Overloads =====
std::ostream	&operator<<(std::ostream &os, const Bureaucrat &src)
{
	os << src.getName() << ", bureaucrat grade " << src.getRange();
	return (os);
}