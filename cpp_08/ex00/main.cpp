#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vect;
	vect.push_back(3);
	vect.push_back(6);
	vect.push_back(8);
	vect.push_back(9);
	vect.push_back(12);

	try
	{
		std::vector<int>::iterator j = easyfind(vect, 8);
		std::cout << "Found: " << *j << std::endl;

		std::vector<int>::iterator h = easyfind(vect, 89);
		std::cout << "Found: " << *h << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

    return 0;
}