#include "Array.hpp"

int main() {

	Array<int> arrEmpty;
	std::cout << "Size of empty array: " << arrEmpty.size() << std::endl;

	unsigned int n = 5;
	Array<int> arrN(n);
	std::cout << "Size of array with n elements: " << arrN.size() << std::endl;

	Array<int> arrCopy(arrN);
	std::cout << "Size of copied array: " << arrCopy.size() << std::endl;

	Array<int> arrAssign;
	arrAssign = arrN;
	std::cout << "Size after assignment: " << arrAssign.size() << std::endl;

	try
	{
		std::cout << "arrAssign[1]: " << arrAssign[1] << std::endl;
		std::cout << "arrAssign[4]: " << arrAssign[4] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// Index [9] -> invalid
	try
	{
		std::cout << arrAssign[9] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

    return 0;
}