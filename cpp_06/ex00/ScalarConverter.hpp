#ifndef SCLARCONVERTER_H
# define SCLARCONVERTER_H

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &model);
		ScalarConverter	&operator=(const ScalarConverter &model);
		~ScalarConverter();
	public:
		static void	convert(const std::string &literal);
};

#endif