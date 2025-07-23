#include "Span.hpp"

// Default constructor will create a vector of size 10
Span::Span(): _N(10), _size(0), _vect(10)
{
	return ;
}

Span::Span(unsigned int n): _N(n), _size(0), _vect(n)
{
	return ;
}

Span::Span(const Span &s)
{
	_vect = s._vect;
	_size = s._size;
	_N = s._N;
}

Span::~Span()
{
	return ;
}

Span &Span::operator=(const Span &s)
{
	_vect = s._vect;
	_size = s._size;
	_N = s._N;
	return (*this);
}

void Span::addNumber(int n)
{
	if (_size == _N)
		throw Span::vectorCompletedException();
	_vect[_size] = n;
	_size++;
}

int Span::shortestSpan()
{
	if (_size <= 1)
		throw Span::vectorEmptySpanException();
	int span = std::numeric_limits<int>::max();
	int rest;
	for (std::vector<int>::iterator it = _vect.begin(); it != _vect.end() - 1; ++it)
	{
		for (std::vector<int>::iterator ite = it + 1; ite != _vect.end(); ++ite)
		{
			rest = std::abs(*it - *ite);
			if (rest < span)
				span = rest;
		}
	}
	return span;
}

int Span::longestSpan()
{
	if (_size <= 1)
		throw Span::vectorEmptySpanException();
	int span = -1;
	int rest;
	for (std::vector<int>::iterator it = _vect.begin(); it != _vect.end() - 1; ++it)
	{
		for (std::vector<int>::iterator ite = it + 1; ite != _vect.end(); ++ite)
		{
			rest = std::abs(*it - *ite);
			if (rest > span)
				span = rest;
		}
	}
	return span;
}

void Span::addRange(int* values, size_t count)
{
	if (_size + count > _N)
    	throw Span::vectorCompletedException();
	for (size_t i = 0; i < count; i++)
		addNumber(values[i]);
}

const char* Span::vectorCompletedException::what() const throw()
{
    return "Vector is already full!";
}

const char* Span::vectorEmptySpanException::what() const throw()
{
    return "Vector has not enough numbers to calculate spin!";
}