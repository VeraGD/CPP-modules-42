#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	return ;
}

Intern::Intern(const Intern &model)
{
	(void)model;
}

Intern::~Intern()
{
	return ;
}

Intern&	Intern::operator=(const Intern &model)
{
	(void)model;
	return *this;
}

AForm* createShrubbery(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidential(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string form, std::string target)
{
	std::string form_names[]= {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*constructors[])(std::string) = {createShrubbery, createRobotomy, createPresidential};

	for(int i = 0; i < 3; i++)
	{
		if (form == form_names[i])
		{
			std::cout << "Intern creates " << form_names[i] << std::endl;
			return constructors[i](target);
		}
	}
	std::cout << form << " doesn't exist, it can't be created " << std::endl;
	return NULL;
}