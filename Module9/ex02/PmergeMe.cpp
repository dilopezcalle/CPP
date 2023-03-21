#include "PmergeMe.hpp"

#include <sys/time.h>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <limits>
#include <vector>
#include <list>

bool	stringIsInteger(char *str);

// Vector prototypes
void	vectorMergeSort(std::vector<int> &v, int start, int end);
void	vectorMerge(std::vector<int> &container, int start, int middle, int end);

// List prototypes
void	listMerge (	std::list<int>& lst, std::list<int>::iterator start,
					std::list<int>::iterator middle, std::list<int>::iterator end);
void	listMergeSort(	std::list<int>& lst, std::list<int>::iterator start,
					std::list<int>::iterator end);


void	mergeSort(char *av[])
{
	std::vector<int>	v;
	std::list<int>		lst;
	double				num;
	double				time;
	long				seg;
	long				u_seg;
	struct timeval		vBeginTime;
	struct timeval		vEndTime;
	struct timeval		lstBeginTime;
	struct timeval		lstEndTime;
	

	for (int i = 0; av[i]; i++)
	{	
		num = std::atof(av[i]);

		if ((std::atoi(av[i]) == 0 && (std::strlen(av[i]) > 1 || av[i][0] != '0')) ||
			(num < 0 || num > std::numeric_limits<int>::max()) || !stringIsInteger(av[i]))
		{
			std::cout << "Error: " << av[i] << " no es un argumento válido\n";
			return ;
		}
		v.push_back(std::atoi(av[i]));
		lst.push_back(std::atoi(av[i]));
	}

	std::cout << "Before:\t";
	for (int i = 0; i < (int)v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << "\n";

	gettimeofday(&vBeginTime, NULL);
	vectorMergeSort(v, 0, v.size() - 1);
	gettimeofday(&vEndTime, NULL);

	gettimeofday(&lstBeginTime, NULL);
	listMergeSort(lst, lst.begin(), lst.end());
	gettimeofday(&lstEndTime, NULL);
	
	std::cout << "After:\t";
	for (int i = 0; i < (int)v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << "\n";

	seg = (vEndTime.tv_sec - vBeginTime.tv_sec) * 1000000;
	u_seg = vEndTime.tv_usec - vBeginTime.tv_usec;
	time = seg + u_seg;
	std::cout << "Time to process a range of " << v.size() << " elements with std::vector\t:\t"
	<< std::setprecision(5) << std::fixed << static_cast<double>(time) << " us\n";

	seg = (lstEndTime.tv_sec - lstBeginTime.tv_sec) * 1000000;
	u_seg = lstEndTime.tv_usec - lstBeginTime.tv_usec;
	time = seg + u_seg;
	std::cout << "Time to process a range of " << lst.size() << " elements with std::list \t:\t"
	<< std::setprecision(5) << std::fixed << static_cast<double>(time) << " us\n";
}

bool	stringIsInteger(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

// ===== Vector =====
void	vectorMergeSort(std::vector<int> &v, int start, int end)
{
	int middle;

	if (start < end)
	{
		// Separate in halves
		middle = (start + end) / 2;

		vectorMergeSort(v, start, middle);
		vectorMergeSort(v, middle + 1, end);

		vectorMerge(v, start, middle, end);
	}
}

void	vectorMerge(std::vector<int> &container, int start, int middle, int end)
{
	std::vector<int> temp(end - start + 1);
	int	j = middle + 1;
	int	i = start;
	int	k = 0;

	// Compare the two halves and order number by number
	while (i <= middle && j <= end)
	{
		if (container[i] <= container[j])
		{
			temp[k] = container[i];
			i++;
		}
		else
		{
			temp[k] = container[j];
			j++;
		}
		k++;
	}

	// In case there are numbers left over in the first half
	while (i <= middle)
	{
		temp[k] = container[i];
		i++;
		k++;
	}

	// In case there are numbers left over in the second half
	while (j <= end)
	{
		temp[k] = container[j];
		j++;
		k++;
	}

	// Save the numbers ordered in the corresponding spot in the original container
	for (int x = start; x <= end; x++)
	{
		container[x] = temp[x - start];
	}
}

// ===== List =====
void listMergeSort(	std::list<int>& lst, std::list<int>::iterator start,
					std::list<int>::iterator end)
{
	std::list<int>::iterator	begin;
	int							i;

	if (std::distance(start, end) > 1)
	{
		begin = start;
		i = std::distance(start, end);
		for (int j = 0; j < i / 2; j++)
			begin++;
		std::list<int>::iterator middle = begin;
		listMergeSort(lst, start, middle);
		listMergeSort(lst, middle, end);
		listMerge(lst, start, middle, end);
	}
}

void	listMerge (	std::list<int>& lst, std::list<int>::iterator start,
					std::list<int>::iterator middle, std::list<int>::iterator end)
{
	std::list<int>				temp;
	std::list<int>::iterator	i = start;
	std::list<int>::iterator	j = middle;
	std::list<int>::iterator	k = end;

	(void)lst;
	// Compare the two halves and order number by number
	while (i != middle && j != k)
	{
		if (*i <= *j)
		{
			temp.push_back(*i);
			i++;
		}
		else
		{
			temp.push_back(*j);
			j++;
		}
	}

	// In case there are numbers left over in the first half
	while (i != middle)
	{
		temp.push_back(*i);
		i++;
	}

	// In case there are numbers left over in the second half
	while (j != k)
	{
		temp.push_back(*j);
		j++;
	}

	// Save the numbers ordered in the corresponding spot in the original container
	for (	std::list<int>::iterator it = start, t_it = temp.begin();
			it != end && t_it != temp.end(); it++, t_it++)
	{
		*it = *t_it;
	}
}
