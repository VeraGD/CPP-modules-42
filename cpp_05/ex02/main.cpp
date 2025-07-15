#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
		std::cout << "---------Sign Forms----------" << std::endl;
        Bureaucrat bob("Bob", 40);
        std::cout << bob << std::endl;

        ShrubberyCreationForm shrubForm("home");
        RobotomyRequestForm robotForm("Bender");
        PresidentialPardonForm pardonForm("Marvin"); // 25 gardeSign, 5 __gradeExecute

        bob.signForm(shrubForm);
        bob.signForm(robotForm);
        bob.signForm(pardonForm);

        std::cout << std::endl;
		std::cout << "---------Execute Forms----------" << std::endl;
        bob.executeForm(shrubForm);
        bob.executeForm(robotForm);
        bob.executeForm(pardonForm);
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

	std::cout << std::endl;
	std::cout << "---------Sign && Execute Form President OK----------" << std::endl;
	Bureaucrat pep("Pep", 3);
	PresidentialPardonForm pres("Pres"); 
	pep.signForm(pres);

	pep.executeForm(pres);

    return 0;
}