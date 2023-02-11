#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include "Bureaucrat.hpp"

int	main(void)
{
	// ===== Without exceptions test =====
	try
	{
		// Create a bureaucrat
		std::cout << YELLOW << "\nSe crea un burócrata" << RESET << std::endl;
		Bureaucrat bureaucrat("Diego", 2);
		std::cout << bureaucrat << std::endl;

		// Tests
		std::cout << YELLOW << "\nTest 1: increment" << RESET << std::endl;
		bureaucrat.incrementRange();
		std::cout << bureaucrat << std::endl;

		std::cout << YELLOW << "\nTest 2: decrement" << RESET << std::endl;
		bureaucrat.decrementRange();
		bureaucrat.decrementRange();
		std::cout << bureaucrat << std::endl;

		std::cout << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) { std::cerr << e.what() << std::endl; }
	catch (Bureaucrat::GradeTooLowException &e) { std::cerr << e.what() << std::endl; }

	std::cout << RED << "\n===== Test de excepciones =====" << RESET << std::endl;

	// ===== Grade too high exception =====
	try
	{
		std::cout << YELLOW << "\nSe crea un burócrata con grado 0" << RESET << std::endl;
		Bureaucrat bureaucrat("Diego", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e) { std::cerr << e.what() << std::endl; }
	catch (Bureaucrat::GradeTooLowException &e) { std::cerr << e.what() << std::endl; }
	try
	{
		std::cout << YELLOW << "\nSe crea un burócrata con grado 1" << RESET << std::endl;
		Bureaucrat bureaucrat("Diego", 1);
		bureaucrat.incrementRange();
	}
	catch (Bureaucrat::GradeTooHighException &e) { std::cerr << e.what() << std::endl; }
	catch (Bureaucrat::GradeTooLowException &e) { std::cerr << e.what() << std::endl; }

	// ===== Grade too low exception =====
	try
	{
		std::cout << YELLOW << "\nSe crea un burócrata con grado 151" << RESET << std::endl;
		Bureaucrat bureaucrat("Diego", 151);
	}
	catch (Bureaucrat::GradeTooHighException &e) { std::cerr << e.what() << std::endl; }
	catch (Bureaucrat::GradeTooLowException &e) { std::cerr << e.what() << std::endl; }

	try
	{
		std::cout << YELLOW << "\nSe crea un burócrata con grado 150" << RESET << std::endl;
		Bureaucrat bureaucrat("Diego", 150);
		bureaucrat.decrementRange();
	}
	catch (Bureaucrat::GradeTooHighException &e) { std::cerr << e.what() << std::endl; }
	catch (Bureaucrat::GradeTooLowException &e) { std::cerr << e.what() << std::endl; }

	return (0);
}