#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
	if (_grade < 1)
		throw Bureaucrat::gradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::gradeTooLowException();
	return ;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade): _name(_name), _grade(_grade)
{
	if (_grade < 1)
		throw Bureaucrat::gradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::gradeTooLowException();
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b): _name(b._name), _grade(b._grade) 
{
	return ;
}
Bureaucrat::~Bureaucrat()
{
	return ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
	if (this != &b)
	{
		_grade = b._grade;
	}
	return *this;
}

std::string Bureaucrat::get_name(void) const
{
	return _name;
}

int Bureaucrat::get_grade(void) const
{
	return _grade;
}

void Bureaucrat::decrement_grade()
{
	if (_grade >= 150)
		throw Bureaucrat::gradeTooLowException();
	_grade = _grade + 1;
}

void Bureaucrat::increment_grade()
{
	if (_grade <= 1)
		throw Bureaucrat::gradeTooHighException();
	_grade = _grade - 1;
}

void Bureaucrat::signForm(AForm& f) const
{
	try 
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.get_name() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << _name << " couldn't sign " << f.get_name();
		std::cout << " because Bureaucrat grade is " << this->get_grade();
		std::cout << " and Form grade to sign is " << f.get_gradeSign() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.get_name() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " cannot execute " << form.get_name() << std::endl;
	}
	
}

const char* Bureaucrat::gradeTooHighException::what() const throw()
{
    return "grade too high!";
}

const char* Bureaucrat::gradeTooLowException::what() const throw()
{
    return "grade too low!";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.get_name() << ", bureaucrat grade " << b.get_grade() << ".";
    return out;
}