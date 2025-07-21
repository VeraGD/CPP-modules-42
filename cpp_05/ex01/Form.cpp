#include "Form.hpp"

Form::Form(): _name("default"), _constructed(false), _gradeSign(1), _gradeExecute(1)
{
	return ;
}

Form::Form(std::string _name, int gs, int ge): _name(_name), _constructed(false), _gradeSign(gs), _gradeExecute(ge)
{
	if (_gradeExecute < 1)
		throw Form::gradeTooHighException();
	if (_gradeExecute > 150)
		throw Form::gradeTooLowException();
	if (_gradeSign < 1)
		throw Form::gradeTooHighException();
	if (_gradeSign > 150)
		throw Form::gradeTooLowException();
	return ;
}

Form::Form(const Form &f): _name(f._name), _constructed(f._constructed), _gradeSign(f._gradeSign), _gradeExecute(f._gradeExecute)
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

int Form::get_gradeSign() const
{
	return _gradeSign;
}

int Form::get_gradeExecute() const
{
	return _gradeExecute;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.get_grade() < _gradeSign)
	{
		if (_constructed == false)
			_constructed = true;
	}
	else
		throw Form::gradeTooLowException();
	std::cout << "<beSigned function>: "<< b.get_name() << " can sign " << this->get_name() << std::endl;
}

const char* Form::gradeTooHighException::what() const throw()
{
    return "grade too high!";
}

const char* Form::gradeTooLowException::what() const throw()
{
    return "grade too low!";
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
	out << f.get_name() << ", form sign grade " << f.get_gradeSign();
	out << ", form execute garde " << f.get_gradeExecute();
    return out;
}