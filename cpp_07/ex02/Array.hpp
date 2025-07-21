#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>
# include <exception>

template<typename T>
class Array
{
	private:
		unsigned int _len;
		T *_a;
	
	public:
		Array();
		Array(unsigned int n); // n is the size, creates and display a
		Array(const Array &array); // copy constructor
		~Array();
		Array &operator=(const Array &array); // assigment operator
		T &operator[](unsigned int i); // [] implementation
		unsigned int size(void);
};

# include "Array.tpp"

#endif