#ifndef INTERN_H
# define INTERN_H

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Intern
{
	public:
	Intern();
	Intern(const Intern &model);
	~Intern();
	Intern& operator=(const Intern &model);
	AForm* makeForm(std::string form, std::string target);
};

#endif