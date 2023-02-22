#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream>
#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

int	main(void)
{
	std::cout << YELLOW
	<< "\nSe crea una instancia de Base = NULL y se identifica"
	<< RESET << std::endl;
	Base *p = NULL;
	identify(p);

	std::cout << YELLOW
	<< "\nSe iguala la Base aleatoriamente a A, B o C y se identifica"
	<< RESET << std::endl;
	p = generate();
	identify(p);
	identify(*p);

	if (p)
		delete p;
}

Base	*generate(void)
{
	int	randomNumber;

	srand(time(NULL));
	randomNumber = rand() % 3;

	if (randomNumber == 0)
		return (new A());
	else if (randomNumber == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base *p)
{
	std::cout << "Identidad con puntero:\t\t";
	A	*a = dynamic_cast<A *>(p);
	B	*b = dynamic_cast<B *>(p);
	C	*c = dynamic_cast<C *>(p);

	if (a)
		std::cout << "A" << std::endl;
	if (b)
		std::cout << "B" << std::endl;
	if (c)
		std::cout << "C" << std::endl;
	if (!a && !b && !c)
		std::cout << "NULL" <<std::endl;
}

void	identify(Base &p)
{
	std::cout << "Identidad con referencia:\t";

	try
	{
		A	&a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			B	&b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				C	&c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << "NULL" << std::endl;
			}
		}
	}
}