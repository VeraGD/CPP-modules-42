#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		RPN r;
		r.calculate(argv[1]);
	}
	else
		std::cout << "Error: invalid arguments" << std::endl;
}