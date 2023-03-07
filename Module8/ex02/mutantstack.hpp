#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	// ===== Constructors =====
	MutantStack<T>()
	{
		return ;
	}
	MutantStack<T>(const MutantStack<T> &src)
	{
		*this = src;
		return ;
	}

	// ===== Operators =====
	MutantStack<T>	&operator=(const MutantStack<T> &src)
	{
		this->c = src.c;
		return (*this);
	}

	// ===== Destructor =====
	~MutantStack<T>()
	{
		return ;
	}

	typedef typename MutantStack<T>::container_type::iterator	iterator;
	iterator	begin()
	{
		return (this->c.begin());
	}
	iterator	end()
	{
		return (this->c.end());
	}
};

#endif