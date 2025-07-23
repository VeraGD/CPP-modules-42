#include "Span.hpp"

int main()
{
	std::cout << "-------Valid span size 5----------" << std::endl;
	Span sp = Span(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "-------Invalid span size 1----------" << std::endl;
	Span sp2 = Span(5);
	try
	{
		sp2.addNumber(6);
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "-------Long span size 10000----------" << std::endl;

	int arr[10000];
	for (int i = 1; i <= 10000; ++i)
		arr[i] = i;

	Span sp3 = Span(10000);
	try
	{
		sp3.addRange(arr, 10000);
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	

	return 0;
}