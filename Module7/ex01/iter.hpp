#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void	iter(T *ptr, int len, void	(*function)(const T &))
{
	for (int i = 0; i < len; i++)
		function(ptr[i]);
}

#endif