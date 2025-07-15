#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;
	AForm* scf;
	scf = someRandomIntern.makeForm("shrubbery creation", "Marvin");
	delete scf;
	AForm* ppf;
	ppf = someRandomIntern.makeForm("presidential pardon", "Pres");
	delete ppf;
	AForm* nn;
	nn = someRandomIntern.makeForm("Forest Try", "tree");
    return 0;
}