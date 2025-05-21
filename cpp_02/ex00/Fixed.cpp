#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
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

Fixed &Fixed::operator=(Fixed& other)
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
