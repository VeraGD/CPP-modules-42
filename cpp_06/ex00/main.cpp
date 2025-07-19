#include "ScalarConverter.hpp"

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string	literal(argv[1]);
		ScalarConverter::convert(literal);
	}
	else
		std::cout << "Invalid arguments" << std::endl;
}