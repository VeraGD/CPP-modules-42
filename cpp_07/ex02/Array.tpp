#include "Array.hpp"

template<typename T>
Array<T>::Array()
{
	_a = new T(0);
	_len = 0;
}

template<typename T>
Array<T>::Array(unsigned int n) // n is the size, creates and display a
{
	_a = new T[n];
	_len = n;
	for (unsigned int i = 0; i < n; i++)
		_a[i] = i;
	
	//display the array
	std::cout << "Array created by default: { ";
	for (unsigned int i = 0; i < n; i++)
		std::cout << _a[i] << " ";
	std::cout << "}" << std::endl;
}

template<typename T>
Array<T>::Array(const Array &array) // copy constructor
{
	_a = new T[array._len];
	_len = array._len;
	for (unsigned int i = 0; i < _len; i++)
		_a[i] = array._a[i];
}

template<typename T>
Array<T>::~Array()
{
	delete[] _a;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &array) // assigment operator
{
	_a = new T[array._len];	
	_len = array._len;
	for (unsigned int i = 0; i < _len; i++)
		_a[i] = array._a[i];
	return (*this);
}

template<typename T>
T &Array<T>::operator[](unsigned int i) // [] implementation
{
	if (i >= _len)
		throw std::out_of_range("Exception: Index out of bounds");
	return (*(_a + i));
}

template<typename T>
unsigned int Array<T>::size(void)
{
	return _len;
}