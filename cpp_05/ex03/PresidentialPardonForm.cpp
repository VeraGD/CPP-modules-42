#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5)
{
	_target = "default ppf";
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5)
{
	_target = target;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &s): AForm("PresidentialPardonForm", 25, 5)
{
	_target = s._target;
	return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &s)
{
	if (this != &s)
	{
		_target = s._target;
	}
	return *this;
}

void PresidentialPardonForm::executeAction(const Bureaucrat&) const
{
	if (get__gradeSign() > 25 || get__gradeExecute() > 5)
		throw AForm::CanNotExecute();
	else
	{
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}