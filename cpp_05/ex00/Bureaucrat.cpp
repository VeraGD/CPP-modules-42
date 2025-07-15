#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
	if (_grade < 1)
		throw Bureaucrat::_gradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::_gradeTooLowException();
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade): _name(_name), _grade(_grade)
{
	if (_grade < 1)
		throw Bureaucrat::_gradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::_gradeTooLowException();
	std::cout << "Constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b): _name(b._name), _grade(b._grade) 
{
	std::cout << "Copy constructor called" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Deconstructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
	if (this != &b)
	{
		std::cout << "Copy assignment operator called" << std::endl;
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
		throw Bureaucrat::_gradeTooLowException();
	_grade = _grade + 1;
}

void Bureaucrat::increment_grade()
{
	if (_grade <= 1)
		throw Bureaucrat::_gradeTooHighException();
	_grade = _grade - 1;
}

const char* Bureaucrat::_gradeTooHighException::what() const throw()
{
    return "grade too high!";
}

const char* Bureaucrat::_gradeTooLowException::what() const throw()
{
    return "grade too low!";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.get_name() << ", bureaucrat grade " << b.get_grade() << ".";
    return out;
}