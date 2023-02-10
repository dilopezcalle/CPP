#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include "Bureaucrat.hpp"

int	main(void)
{
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
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}