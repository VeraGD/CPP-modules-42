#ifndef AFORM_H
# define AFORM_H

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _constructed;
		int const _gradeSign;
		int const _gradeExecute;
	public:
		AForm();
		AForm(std::string _name, int gs, int ge);
		AForm(const AForm &f);
		virtual ~AForm();
		AForm& operator=(const AForm &f);
		std::string get_name() const;
		bool get_constructed() const;
		int get_gradeSign() const;
		int get_gradeExecute() const;
		virtual void beSigned(const Bureaucrat &b);
		virtual void execute(const Bureaucrat& executor) const;
		virtual void executeAction(const Bureaucrat& executor) const  = 0;

		class gradeTooHighException : public std::exception {
			const char* what() const throw();
		};
	
		class gradeTooLowException : public std::exception {
			const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			const char* what() const throw();
		};

		class CanNotExecute : public std::exception {
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif