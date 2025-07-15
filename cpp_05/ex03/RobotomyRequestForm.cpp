#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45)
{
	_target = "default rrf";
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &s): AForm("RobotomyRequestForm", 72, 45)
{
	_target = s._target;
	return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &s)
{
	if (this != &s)
	{
		_target = s._target;
	}
	return *this;
}

void RobotomyRequestForm::executeAction(const Bureaucrat&) const
{
	if (get__gradeSign() > 72 || get__gradeExecute() > 45)
	{
		std::cout << "Robotomy failed" << std::endl;
		throw AForm::CanNotExecute();
	}
	else
	{
		std::cout << "brrrrrrrrrrrrr............." << std::endl;
		std::cout << _target << " has been robotomized successfully 50% of the time" << std::endl;
	}
}