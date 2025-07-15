#include "Form.hpp"

Form::Form(): _name("default"), _constructed(false), __gradeSign(1), __gradeExecute(1)
{
	return ;
}

Form::Form(std::string _name, int gs, int ge): _name(_name), _constructed(false), __gradeSign(gs), __gradeExecute(ge)
{
	if (__gradeExecute < 1)
		throw Form::_gradeTooHighException();
	if (__gradeExecute > 150)
		throw Form::_gradeTooLowException();
	if (__gradeSign < 1)
		throw Form::_gradeTooHighException();
	if (__gradeSign > 150)
		throw Form::_gradeTooLowException();
	return ;
}

Form::Form(const Form &f): _name(f._name), _constructed(f._constructed), __gradeSign(f.__gradeSign), __gradeExecute(f.__gradeExecute)
{
	return ;
}

Form::~Form()
{
	return ;
}

Form& Form::operator=(const Form &f)
{
	if (this != &f)
	{
		_constructed = f._constructed;
	}
	return *this;
}

std::string Form::get_name() const
{
	return _name;
}

bool Form::get_constructed() const
{
	return _constructed;
}

int Form::get__gradeSign() const
{
	return __gradeSign;
}

int Form::get__gradeExecute() const
{
	return __gradeExecute;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.get_grade() < __gradeSign)
	{
		if (_constructed == false)
			_constructed = true;
	}
	else
		throw Form::_gradeTooLowException();
	std::cout << "<beSigned function>: "<< b.get_name() << " can sign " << this->get_name() << std::endl;
}

const char* Form::_gradeTooHighException::what() const throw()
{
    return "grade too high!";
}

const char* Form::_gradeTooLowException::what() const throw()
{
    return "grade too low!";
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
	out << f.get_name() << ", form sign grade " << f.get__gradeSign();
	out << ", form execute garde " << f.get__gradeExecute();
    return out;
}