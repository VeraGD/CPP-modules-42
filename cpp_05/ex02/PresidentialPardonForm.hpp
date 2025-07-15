#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include <iostream>
#include <exception>
#include <fstream>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &s);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &s);
		void executeAction(const Bureaucrat&) const;
};

#endif