#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include <iostream>
#include <exception>
#include <fstream>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &s);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &s);
		void executeAction(const Bureaucrat&) const;
};

#endif