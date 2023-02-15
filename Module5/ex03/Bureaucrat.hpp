#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	// ===== Attributes =====
	std::string	_name;
	int			_range;

public:
	// ===== Constructors =====
	Bureaucrat();
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat(std::string name, int range);

	// ===== Destructor =====
	~Bureaucrat();

	// ===== Operators =====
	Bureaucrat	&operator=(const Bureaucrat &src);

	// ===== Getters =====
	std::string	getName(void) const;
	int			getRange(void) const;

	// ===== Methods =====
	void	incrementRange(void);
	void	decrementRange(void);
	int		signForm(AForm &src);
	int		executeForm(const AForm &form);

	// ===== Exceptions =====
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("BureaucratException: Grade too high");
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("BureaucratException: Grade too low");
			}
	};
};

// ===== Overloads =====
std::ostream	&operator<<(std::ostream &os, const Bureaucrat &src);

#endif