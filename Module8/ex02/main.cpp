#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream>

#include "mutantstack.hpp"

int main()
{
	MutantStack<int>::iterator it;
	MutantStack<int>::iterator ite;

	std::cout << YELLOW << "\nSe crea un MutantStack de enteros y se agregan números"
	<< RESET << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "El tamaño del Stack es de: " << mstack.size() << std::endl;
	it = mstack.begin();
	ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << ", ";
		++it;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "\nCreo un nuevo MutantStack copiando el anterior"
	<< RESET << std::endl;
	MutantStack<int>	copy(mstack);
	it = copy.begin();
	ite = copy.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << ", ";
		++it;
	}
	std::cout << std::endl;
	return (0);
}
