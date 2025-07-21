#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm::AForm(): _name("default"), _constructed(false), _gradeSign(1), _gradeExecute(1)
{
	return ;
}

AForm::AForm(std::string _name, int gs, int ge): _name(_name), _constructed(false), _gradeSign(gs), _gradeExecute(ge)
{
	if (_gradeExecute < 1)
		throw AForm::gradeTooHighException();
	if (_gradeExecute > 150)
		throw AForm::gradeTooLowException();
	if (_gradeSign < 1)
		throw AForm::gradeTooHighException();
	if (_gradeSign > 150)
		throw AForm::gradeTooLowException();
	return ;
}

AForm::AForm(const AForm &f): _name(f._name), _constructed(f._constructed), _gradeSign(f._gradeSign), _gradeExecute(f._gradeExecute)
{
	return ;
}

AForm::~AForm()
{
	return ;
}

AForm& AForm::operator=(const AForm &f)
{
	if (this != &f)
	{
		_constructed = f._constructed;
	}
	return *this;
}

std::string AForm::get_name() const
{
	return _name;
}

bool AForm::get_constructed() const
{
	return _constructed;
}

int AForm::get_gradeSign() const
{
	return _gradeSign;
}

int AForm::get_gradeExecute() const
{
	return _gradeExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.get_grade() < _gradeSign)
	{
		if (_constructed == false)
			_constructed = true;
	}
	else
		throw AForm::gradeTooLowException();
	std::cout << "<beSigned function>: "<< b.get_name() << " can sign " << this->get_name() << std::endl;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (!_constructed)
		throw FormNotSignedException();
	if (executor.get_grade() > _gradeExecute)
		throw gradeTooLowException();
	this->executeAction(executor);
}

const char* AForm::gradeTooHighException::what() const throw()
{
    return "grade too high!";
}

const char* AForm::gradeTooLowException::what() const throw()
{
    return "grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

const char* AForm::CanNotExecute::what() const throw()
{
    return "Form cannot be executed, grade too low";
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
	out << f.get_name() << ", form sign grade " << f.get_gradeSign();
	out << ", form execute garde " << f.get_gradeExecute();
    return out;
}