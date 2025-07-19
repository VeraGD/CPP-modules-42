#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &model) {
	(void)model;
	return ;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &model) {
	(void)model;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	return ;
}

int ft_strlen(const std::string &literal)
{
	int i = 0;
	while (literal[i])
	{
		i++;
	}
	return (i);
}

template <typename T>
void printC(const T &to_print, int flag)
{
	// CHAR
	char c = static_cast<unsigned char>(to_print);

	if (flag == 0)
	{
		if ((!std::isprint(c) && to_print < 254 &&  to_print > 32) || (to_print == 0))
			std::cout << "char: Non displayable" << std::endl;
		else if (std::isnan(c) ||  to_print < 32 || to_print > 127)
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(to_print) <<"'" << std::endl;
	}
	else
	{
		if (std::isnan(to_print) || to_print < 32 || to_print > 127)
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(to_print) << std::endl;
	}
	
	// INT
	if (std::isnan(to_print) ||to_print < static_cast<double>(std::numeric_limits<int>::min()) || to_print > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(to_print) << std::endl;
	
	//FLOAT
	float f = static_cast<float>(to_print);
	
	if (std::isinf(f) || std::isnan(f))
		std::cout << "float: " << f << "f" << std::endl;
	else if (to_print < -std::numeric_limits<float>::max() || to_print > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
	
	// DOUBLE
	double d = static_cast<double>(to_print);
	if (std::isinf(d) || std::isnan(d))
		std::cout << "double: " << d << std::endl;
	else if (to_print < -std::numeric_limits<double>::max() || to_print > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}

int is_int(const std::string &literal)
{
	int i = 0;
	if (literal[0] == '+' || literal[0] == '-')
		i = 1;
	while (literal[i])
	{
		if (literal[i] < '0' || literal[i] > '9')
			return 0;
		i++;
	}
	return 1;
}

int is_float(const std::string &literal)
{
	int c = 0; // counter for '.' char
	int f = 0; // counter to check f at the end of the string
	int l = ft_strlen(literal); // length
	int i = 0;

	if (literal[0] == '+' || literal[0] == '-')
		i = 1;
	while (literal[i])
	{
		if (literal[i] == '.')
			c++;
		else if (literal[i] == 'f' && i == l -1)
			f++;
		else if (literal[i] < '0' || literal[i] > '9')
			return 0;
		i++;
	}
	if (c != 1 || f != 1)
		return 0; // there is no one '.' and there is no 'f' at the final
	else
		return 1;
}

int is_double(const std::string &literal)
{
	int c = 0; // counter for '.' char
	int i = 0;

	if (literal[0] == '+' || literal[0] == '-')
		i = 1;
	while (literal[i])
	{
		if (literal[i] == '.')
			c++;
		else if (literal[i] < '0' || literal[i] > '9')
			return 0;
		i++;
	}
	if (c != 1)
		return 0; // there is no one '.' 
	else
		return 1;
}

void	ScalarConverter::convert(const std::string &literal)
{
	if (literal == "nan" || literal == "nanf") // ESPECIAL NAN, NANF
		printC(std::numeric_limits<double>::quiet_NaN(), 1);
	else if (literal == "inf" || literal == "+inf" || literal == "inff" || literal == "+inff") // ESPECIAL INF, INFF
		printC(std::numeric_limits<double>::infinity(), 1);
	else if (literal == "-inf" || literal == "-inff") // ESPECIAL -INF, -INFF
		printC(-std::numeric_limits<double>::infinity(), 1);
	else if (is_int(literal) == 1) // INT
		printC(std::strtol(literal.c_str(), NULL, 10), 0);
	else if (literal.size() == 1) // CHAR
		printC(literal[0], 0);
	else if (literal.size() == 2 && !std::isprint(static_cast<unsigned char>(literal[0]))) // CHAR NON PRINTABLE
		printC(static_cast<unsigned char>(literal[0]), 0);
	else if (is_float(literal) == 1) // FLOAT
		printC(std::strtof(literal.c_str(), NULL), 0);
	else if (is_double(literal) == 1) // DOUBLE
		printC(std::strtod(literal.c_str(), NULL), 0);
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}