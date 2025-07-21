#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137)
{
	_target = "default scf";
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):  AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s): AForm("ShrubberyCreationForm", 145, 137)
{
	_target = s._target;
	return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s)
{
	if (this != &s)
	{
		_target = s._target;
	}
	return *this;
}

void ShrubberyCreationForm::executeAction(const Bureaucrat&) const
{
	if (get_gradeSign() > 145 || get_gradeExecute() > 137)
		throw AForm::CanNotExecute();
	else
	{
		std::ofstream file((_target + "_shrubbery.txt").c_str());
		if (!file)
		{
			std::cerr << "Error creating the new file" << std::endl;
			return ;
		}
		file << "       ^          ^          ^       \n";
		file << "      /|\\        /|\\        /|\\      \n";
		file << "     //|\\\\      //|\\\\      //|\\\\     \n";
		file << "    ///|\\\\\\    ///|\\\\\\    ///|\\\\\\    \n";
		file << "      ||         ||         ||      \n";
		file << "     /__\\       /__\\       /__\\     \n";
		file.close();
	}
}