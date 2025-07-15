#ifndef FORM_H
# define FORM_H

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _constructed;
		int const __gradeSign;
		int const __gradeExecute;
	public:
		Form();
		Form(std::string _name, int gs, int ge);
		Form(const Form &f);
		~Form();
		Form& operator=(const Form &f);
		std::string get_name() const;
		bool get_constructed() const;
		int get__gradeSign() const;
		int get__gradeExecute() const;
		void beSigned(const Bureaucrat &b);

		class _gradeTooHighException : public std::exception {
			const char* what() const throw();
		};
	
		class _gradeTooLowException : public std::exception {
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif