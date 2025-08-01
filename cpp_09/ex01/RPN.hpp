#ifndef RPN_H
# define RPN_H

# include <iostream>
# include <stack>
# include <cstdlib>

class RPN
{
	private:
		std::stack<int> s; // container

		RPN(const RPN& r);
		RPN& operator=(const RPN& r);
		int check_input_valid(std::string *input);
		std::string *check_input_char(std::string input);
		void made_op(std::string *r, int i);
	public:
		RPN();
		~RPN();
		void calculate(std::string input);
};

#endif