#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template<typename T>
class Array
{
private:
	// ===== Attributes =====
	T				*_array;
	unsigned int	_size;

public:

	// ===== Constructor =====
	Array<T>()
	{
		this->_array = new T[0];
		this->_size = 0;
		return ;
	}
	Array<T>(unsigned int n)
	{
		this->_array = new T[n];
		this->_size = n;
		return ;
	}
	Array<T>(const Array &src)
	{
		*this = src;
		return ;
	}

	// ===== Destructor =====
	~Array()
	{
		delete []this->_array;
	}

	// ===== Operator =====
	Array	&operator=(const Array<T> &src)
	{
		this->_array = src.getArray();
		this->_size = src.getSize();
		return (*this);
	}
	T		&operator[](int index)
	{
		if (index < 0)
			throw std::exception();
		if (index >= (int)this->_size)
			throw std::exception();
		return (this->_array[index]);
	}

	// ===== Getters =====
	T	*getArray(void) const
	{
		T	*array = new T[this->_size];
		for (int i = 0; i < this->_size; i++)
			array[i] = this->_array[i];
		return (array);
	}
	unsigned int	size(void) const
	{
		return (this->_size);
	}
};

#endif