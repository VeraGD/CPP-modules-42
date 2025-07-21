#include <iostream>

template<typename T>
void iter(T* array, size_t len, T (*f)(T))
{
	for (size_t i = 0; i < len ;i++)
	{
		array[i] = f(array[i]);
	}
}