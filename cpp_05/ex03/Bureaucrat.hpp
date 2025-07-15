#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
		const std::string	_name;
		int					_grade;
    
    public:
		Bureaucrat();
		Bureaucrat(std::string _name, int _grade);
		Bureaucrat(const Bureaucrat& b);
        ~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& b);
		std::string get_name(void) const;
		int get_grade(void) const;
		void decrement_grade();
		void increment_grade();
		void signForm(AForm& f) const;
		void executeForm(AForm const & form) const;

		class _gradeTooHighException : public std::exception {
			const char* what() const throw();
		};
	
		class _gradeTooLowException : public std::exception {
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif