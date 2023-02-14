#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	// ===== Create the forms =====
	std::cout << YELLOW << "\nSe crean los tres tipos de formularios" << RESET << std::endl;
	AForm	*form1 = new ShrubberyCreationForm("test");
	AForm	*form2 = new RobotomyRequestForm("Pepe");
	AForm	*form3 = new PresidentialPardonForm("Pepe");

	Bureaucrat	*bureaucrat = NULL;

	// ===== Shrubbery tests =====
	std::cout << YELLOW << "\nPruebas del formulario "
	<< *form1 << "\n" << RESET << std::endl;

	bureaucrat = new Bureaucrat("Diego", 150);
	std::cout << *bureaucrat << std::endl;
	bureaucrat->signForm(*form1);
	bureaucrat->executeForm(*form1);
	delete bureaucrat;

	std::cout << std::endl;
	bureaucrat = new Bureaucrat("Diego", 137);
	std::cout << *bureaucrat << std::endl;
	bureaucrat->executeForm(*form1);
	bureaucrat->signForm(*form1);
	bureaucrat->executeForm(*form1);
	delete bureaucrat;

	// ===== Robotomy tests =====
	std::cout << YELLOW << "\nPruebas del formulario "
	<< *form2 << "\n" << RESET << std::endl;

	bureaucrat = new Bureaucrat("Diego", 150);
	std::cout << *bureaucrat << std::endl;
	bureaucrat->signForm(*form2);
	bureaucrat->executeForm(*form2);
	delete bureaucrat;

	std::cout << std::endl;
	bureaucrat = new Bureaucrat("Diego", 45);
	std::cout << *bureaucrat << std::endl;
	bureaucrat->executeForm(*form2);
	bureaucrat->signForm(*form2);
	bureaucrat->executeForm(*form2);
	delete bureaucrat;

	// ===== Presidential tests =====
	std::cout << YELLOW << "\nPruebas del formulario "
	<< *form3 << "\n" << RESET << std::endl;

	bureaucrat = new Bureaucrat("Diego", 150);
	std::cout << *bureaucrat << std::endl;
	bureaucrat->signForm(*form3);
	bureaucrat->executeForm(*form3);
	delete bureaucrat;

	std::cout << std::endl;
	bureaucrat = new Bureaucrat("Diego", 5);
	std::cout << *bureaucrat << std::endl;
	bureaucrat->executeForm(*form3);
	bureaucrat->signForm(*form3);
	bureaucrat->executeForm(*form3);
	delete bureaucrat;

	// Free memory
	std::cout << YELLOW << "\nSe libera la memoria" << RESET << std::endl;
	delete form1;
	delete form2;
	delete form3;

	return (0);
}