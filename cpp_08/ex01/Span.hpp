#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <vector>
# include <limits>
# include <cstdlib>

class Span
{
	private:
		unsigned int _N;
		size_t _size;
		std::vector<int> _vect;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &s);
		~Span();
		Span &operator=(const Span &s);
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		void addRange(int* values, std::size_t count);
	
		class vectorCompletedException: public std::exception {
			const char* what() const throw();
		};
		class vectorEmptySpanException: public std::exception {
			const char* what() const throw();
		};
};

#endif