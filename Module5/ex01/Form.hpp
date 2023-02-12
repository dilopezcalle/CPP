#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	// ===== Attributes =====
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeSign;
	const int			_gradeExec;

public:
	// ===== Constructors =====
	Form();
	Form(const Form &src);
	Form(std::string name, int gradeSign, int gradeExec);

	// ===== Destructor =====
	~Form();

	// ===== Operators =====
	Form	&operator=(const Form &src);

	// ===== Getters =====
	const std::string	getName(void) const;
	bool				getIsSigned(void) const;
	int					getGradeSign(void) const;
	int					getGradeExec(void) const;

	// ===== Methods =====
	int	beSigned(const Bureaucrat &src);

	// ===== Exceptions =====
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("FormException: Grade too high");
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("FormException: Grade too low");
		}
	};
};

std::ostream	&operator<<(std::ostream &os, const Form &src);

#endif