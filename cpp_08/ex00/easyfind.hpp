#ifndef EASYFIND_H
# define EASYFIND_H

# include <iostream>
# include <vector>
# include <algorithm>

template<typename T>
typename T::iterator easyfind(T& vec, int to_find)
{
	for (typename T::iterator it = vec.begin() ; it != vec.end(); ++it)
	{
		if (*it == to_find)
			return it;
	}
	throw std::runtime_error("Error: number could not be found in the container.");
};

#endif
