#include "RPN.hpp"

RPN::RPN() { }

RPN::RPN(const RPN& r)
{
	s = r.s;
}

RPN::~RPN() { }

RPN& RPN::operator=(const RPN& r)
{
	if (s != r.s)
		s = r.s;
	return *this;
}

// check if first and second are numbers and last is operator
int RPN::check_input_valid(std::string *input)
{
	for (size_t i = 0; i < input->size(); ++i)
	{
		if ((i == 0 || i == 1) && (*input)[i] < '0' )
		{
			std::cout << "Error: invalid RPN" << std::endl;
			delete input;
			return 1;
		}
		else if ( i == input->size() - 1 && ((*input)[i] != '+' && (*input)[i] != '-' 
			&& (*input)[i] != '*' && (*input)[i] != '/'))
		{
			std::cout << "Error: invalid RPN" << std::endl;
			delete input;
			return 1;
		}
	}
	return 0;
}

// get RPN in std::string * and check chars and less than 10
std::string *RPN::check_input_char(std::string input)
{
	std::string *res =  new std::string();

	unsigned int i = 0;
	while (input[i])
	{
		if (i + 1 < input.size() && (input[i] >= '0' && input[i] <= '9' && input[i + 1] == ' '))
			res->push_back(input[i]);
		else if ((input[i] == '+'  || input[i] == '-' || input[i] == '*' 
				|| input[i] == '/') && (input[i + 1] == ' ' || i + 1 == input.size()))
			res->push_back(input[i]);
		else if (input[i] != ' ')
		{
			std::cout << "Error: invalid format" << std::endl;
			delete res;
			return NULL;
		}
		i++;
	}
	if (check_input_valid(res) == 0)
		return res;
	else
		return NULL;
}

// RPM algorithm just the operations
void RPN::made_op(std::string *r, int i)
{
	int k = s.top();
	s.pop();
	int j = s.top();
	s.pop();
	if ((*r)[i] == '+')
		s.push(j + k);
	else if ((*r)[i] == '-')
		s.push(j - k);
	else if ((*r)[i] == '*')
		s.push(j * k);
	else
		s.push(j / k);
}

// RPM algorithm, push numbers and operations
// https://ianmcloughlin.github.io/reverse_polish_notation/
void RPN::calculate(std::string input)
{
	std::string* r = check_input_char(input);
	if (r == NULL)
		return ;
	for (size_t i = 0; i < r->size(); ++i)
	{
		if ((*r)[i] >= '0' && (*r)[i] <= '9')
			s.push((*r)[i] - '0');
		else
		{
			if (s.size() >= 2)
				made_op(r, i);
			else
			{
				std::cout << "Error: invalid RPN" << std::endl;
				return ;
			}
		}
	}
	delete r;
	if (s.size() != 1)
	{
		std::cout << "Error: invalid RPN" << std::endl;
		return ;
	}
	else
		std::cout << s.top() << std::endl;
}
