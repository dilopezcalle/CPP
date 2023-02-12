#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Form *myForm = NULL;

	// ===== Form exceptions tests =====
	std::cout << YELLOW << "\nTests para LowException de un formulario" << RESET << std::endl;
	try
	{
		myForm = new Form("myForm", 5, 151);
	}
	catch(std::exception &e) { std::cerr << e.what() << std::endl; }
	try
	{
		myForm = new Form("myForm", 151, 5);
	}
	catch(std::exception &e) { std::cerr << e.what() << std::endl; }

	std::cout << YELLOW << "\nTests para HighException de un formulario" << RESET << std::endl;
	try
	{
		myForm = new Form("myForm", 1, 0);
	}
	catch(std::exception &e) { std::cerr << e.what() << std::endl; }
	try
	{
		myForm = new Form("myForm", 0, 1);
	}
	catch(std::exception &e) { std::cerr << e.what() << std::endl; }

	if (myForm)
		delete myForm;

	// ===== Creating a form and two bureaucrats =====
	std::cout << YELLOW << "\nSe crea un formulario y dos burócratas" << RESET << std::endl;
	Bureaucrat *me = NULL;
	Bureaucrat *other = NULL;
	try
	{
		myForm = new Form("myForm", 5, 5);
		me = new Bureaucrat("me", 5);
		other = new Bureaucrat("other", 6);
	}
	catch(std::exception &e) { std::cerr << e.what() << std::endl; }

	// If exception happens
	if (!myForm || !me || !other)
	{
		if (myForm)
			delete myForm;
		if (me)
			delete me;
		if (other)
			delete other;
	}

	std::cout << "\n" << *myForm << "\n" << *me << "\n" << *other << std::endl;

	// Sign tests
	std::cout << YELLOW << "\nFirmas" << RESET << std::endl;	
	other->signForm(*myForm);
	me->signForm(*myForm);

	std::cout << YELLOW << "\nSe incrementa en 2 el rango de " << other->getName() << RESET << std::endl;
	other->incrementRange();
	other->incrementRange();
	std::cout << *other << std::endl;
	other->signForm(*myForm);

	// Free memory
	std::cout << YELLOW << "\nSe libera la memoria reservada" << RESET << std::endl;
	if (myForm)
		delete myForm;
	if (me)
		delete me;
	if (other)
		delete other;	

	return (0);
}