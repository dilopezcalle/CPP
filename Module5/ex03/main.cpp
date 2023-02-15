#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	// Create a intern and test with nonexistent form
	std::cout << YELLOW << "\nSe crea un interno y crea un formulario inexistente" << RESET << std::endl;
	Intern	intern;
	AForm	*form;
	form = intern.makeForm("no existe", "test");
	(void)form;

	// ===== Create the forms =====
	std::cout << YELLOW << "\nEl interno crea los tres tipos de formularios" << RESET << std::endl;
	AForm	*form1 = intern.makeForm("shrubbery creation", "test");
	AForm	*form2 = intern.makeForm("robotomy request", "Pepe");
	AForm	*form3 = intern.makeForm("presidential pardon", "Pepe");

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