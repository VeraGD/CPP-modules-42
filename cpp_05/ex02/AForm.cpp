#include "AForm.hpp"

AForm::AForm(): _name("default"), _constructed(false), __gradeSign(1), __gradeExecute(1)
{
	return ;
}

AForm::AForm(std::string _name, int gs, int ge): _name(_name), _constructed(false), __gradeSign(gs), __gradeExecute(ge)
{
	if (__gradeExecute < 1)
		throw AForm::_gradeTooHighException();
	if (__gradeExecute > 150)
		throw AForm::_gradeTooLowException();
	if (__gradeSign < 1)
		throw AForm::_gradeTooHighException();
	if (__gradeSign > 150)
		throw AForm::_gradeTooLowException();
	return ;
}

AForm::AForm(const AForm &f): _name(f._name), _constructed(f._constructed), __gradeSign(f.__gradeSign), __gradeExecute(f.__gradeExecute)
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

int AForm::get__gradeSign() const
{
	return __gradeSign;
}

int AForm::get__gradeExecute() const
{
	return __gradeExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.get_grade() < __gradeSign)
	{
		if (_constructed == false)
			_constructed = true;
	}
	else
		throw AForm::_gradeTooLowException();
	std::cout << "<beSigned function>: "<< b.get_name() << " can sign " << this->get_name() << std::endl;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (!_constructed)
		throw FormNotSignedException();
	if (executor.get_grade() > __gradeExecute)
		throw _gradeTooLowException();
	this->executeAction(executor);
}

const char* AForm::_gradeTooHighException::what() const throw()
{
    return "grade too high!";
}

const char* AForm::_gradeTooLowException::what() const throw()
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
	out << f.get_name() << ", form sign grade " << f.get__gradeSign();
	out << ", form execute garde " << f.get__gradeExecute();
    return out;
}