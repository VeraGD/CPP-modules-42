#include "iter.hpp"

template<typename T>
T sum_one(T t)
{
	return t + 1;
}

int main(void)
{
	int array[] = {1, 2, 3, 4, 5};
	size_t len = 5;

	std::cout << "before iter: ";
	for (size_t i = 0; i < len; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;

	iter(array, len, sum_one); // iter

	std::cout << "after iter: ";
	for (size_t i = 0; i < len; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;

	char array_c[] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << std::endl;
	std::cout << "before iter: ";
	for (size_t i = 0; i < len; i++)
		std::cout << array_c[i] << " ";
	std::cout << std::endl;

	iter(array_c, len, sum_one); // iter

	std::cout << "after iter: ";
	for (size_t i = 0; i < len; i++)
		std::cout << array_c[i] << " ";
	std::cout << std::endl;
}