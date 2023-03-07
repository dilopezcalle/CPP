#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template<typename T>
typename T::iterator	easyfind(T container, int index)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), index);
	if (it == container.end())
		throw std::exception();
	std::cout << "El número " << index << " está en la posición "
	<< *it << std::endl;
	return (it);
};

#endif