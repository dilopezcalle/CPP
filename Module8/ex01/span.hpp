#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span
{
private:
	// ===== Attributes =====
	std::vector<int>	_vecInt;
	unsigned int		_len;

public:
	// ===== Constructors =====
	Span();
	Span(const Span &src);
	Span(unsigned int N);

	// ===== Operators =====
	Span	&operator=(const Span &src);

	// ===== Destructor =====
	~Span();

	// ===== Methods =====
	void	addNumber(int newNumber);
	void	generateNewSpan(unsigned int randomNumbers);
	int		shortestSpan(void);
	int		longestSpan(void);
	void	printSpan(void);
};

#endif