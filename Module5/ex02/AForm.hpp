#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	// ===== Attributes =====
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeSign;
	const int			_gradeExec;

public:
	// ===== Constructors =====
	AForm();
	AForm(const AForm &src);
	AForm(std::string name, int gradeSign, int gradeExec);

	// ===== Destructor =====
	virtual ~AForm();

	// ===== Operators =====
	AForm	&operator=(const AForm &src);

	// ===== Getters =====
	const std::string	getName(void) const;
	bool				getIsSigned(void) const;
	int					getGradeSign(void) const;
	int					getGradeExec(void) const;

	// ===== Setters =====
	void	setIsSigned(bool isSigned);

	// ===== Methods =====
	int	beSigned(const Bureaucrat &src);
	virtual int	execute(const Bureaucrat &executor) const = 0;

	// ===== Exceptions =====
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("AFormException: Grade too high");
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("AFormException: Grade too low");
		}
	};
	class NotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("AFormException: Form not signed");
		}
	};
};

std::ostream	&operator<<(std::ostream &os, const AForm &src);

#endif