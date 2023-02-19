#ifndef DATA_HPP
# define DATA_HPP

# include <string>

struct Data
{
	std::string	name;
	int			size;
};

uintptr_t	serialize(Data *ptr);
Data		*deserialize(uintptr_t raw);

#endif