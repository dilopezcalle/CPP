#include "span.hpp"

#include <algorithm>
#include <iostream>
#include <cstdlib>

// ===== Constructors =====
Span::Span() : _vecInt(0), _len(0)
{
	return ;
}
Span::Span(const Span &src)
{
	*this = src;
	return ;
}
Span::Span(unsigned int N) : _len(N)
{
	this->_vecInt.reserve(N);
	return ;
}

// ===== Operators =====
Span	&Span::operator=(const Span &src)
{
	std::vector<int>	copy = src._vecInt;
	std::vector<int>::iterator	begin = copy.begin();

	this->_len = src._len;
	this->_vecInt.reserve(src._len);
	while (begin != copy.end())
	{
		this->addNumber(*begin);
		begin++;
	}
	return (*this);
}

// ===== Destructor =====
Span::~Span()
{
	return ;
}

// ===== Methods =====
void	Span::addNumber(int newNumber)
{
	if (this->_vecInt.size() >= this->_len)
		throw std::exception();
	this->_vecInt.push_back(newNumber);
}

int	randomNumber(void)
{
	return (std::rand() % 10000);
}

void	Span::generateNewSpan(unsigned int randomNumbers)
{
	std::vector<int>	randomVector(randomNumbers);

	if (randomNumbers < 1)
		throw std::exception();
	
	srand(time(NULL));
	std::generate(randomVector.begin(), randomVector.end(), randomNumber);
	this->_vecInt = randomVector;
}

int		Span::shortestSpan(void)
{
	int	shortest = 2147483647;
	std::vector<int>::iterator	begin;
	std::vector<int>	vecSort = this->_vecInt;

	if (this->_vecInt.size() == 0 || this->_vecInt.size() == 1)
		throw std::exception();

	std::sort(vecSort.begin(), vecSort.end());
	begin = vecSort.begin();

	while (begin + 1 != vecSort.end())
	{
		if (shortest > (*(begin + 1) - *begin))
			shortest = *(begin + 1) - *begin;
		begin++;
	}
	return (shortest);
}

int		Span::longestSpan(void)
{
	int	longest;

	if (this->_vecInt.size() == 0 || this->_vecInt.size() == 1)
		throw std::exception();

	longest = *(std::max_element(this->_vecInt.begin(), this->_vecInt.end()));
	longest -= *(std::min_element(this->_vecInt.begin(), this->_vecInt.end()));
	return (longest);
}

void	Span::printSpan(void)
{
	std::vector<int>::iterator	begin = this->_vecInt.begin();
	
	while (begin != this->_vecInt.end())
	{
		std::cout << *begin << ", ";
		begin++;
	}
	std::cout << std::endl;
}