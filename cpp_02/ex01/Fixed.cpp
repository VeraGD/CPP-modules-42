#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    //fp_value = value;
    fp_value = value * (1 << f_bits);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
    fp_value = roundf(value * (1 << f_bits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) // si fuese otro valor y no 0 -> this->fp_value = fixed.fp_value
{
    if (this == &fixed)
		return ;
	std::cout << "Copy constructor called" << std::endl;
	fp_value = fixed.fp_value;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

/* Fixed &Fixed::operator=(Fixed& other)
{
    if (this != &other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		fp_value = other.fp_value;
	}
	return *this;
} */

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        fp_value = other.fp_value;
    }
    return *this;
}

int Fixed::getRawBits(void)
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fp_value;
}

void Fixed::setRawBits(int const raw)
{
    fp_value = raw;
    std::cout << "setRawBits member function called" << std::endl;
}

int Fixed::toInt(void) const
{
    return fp_value / (1 << f_bits);
}

float Fixed::toFloat(void) const
{
    return fp_value / (float)(1 << f_bits);
}

/* std::ostream& Fixed::operator<<(const Fixed& f)
{
    std::cout << f.toFloat();
    return std::cout;
} */

std::ostream& operator<<(std::ostream& out, const Fixed& f) {
    out << f.toFloat();
    return out;
}
