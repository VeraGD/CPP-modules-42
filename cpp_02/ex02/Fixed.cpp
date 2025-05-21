#include "Fixed.hpp"

Fixed::Fixed()
{
    return ;
}

Fixed::Fixed(const int value)
{
    //fp_value = value;
    fp_value = value * (1 << f_bits);
}

Fixed::Fixed(const float value)
{
    fp_value = roundf(value * (1 << f_bits));
}

Fixed::Fixed(const Fixed& fixed) // si fuese otro valor y no 0 -> this->fp_value = fixed.fp_value
{
    if (this == &fixed)
		return ;
	fp_value = fixed.fp_value;
}

Fixed::~Fixed()
{
    return ;
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

int Fixed::getRawBits(void) const
{
    return fp_value;
}

void Fixed::setRawBits(int const raw)
{
    fp_value = raw;
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

//OPERATORS
bool Fixed::operator>(const Fixed& other)
{
    return  this->fp_value > other.fp_value;
}

bool Fixed::operator<(const Fixed& other)
{
    return  this->fp_value < other.fp_value;
}

bool Fixed::operator>=(const Fixed& other)
{
    return  this->fp_value >= other.fp_value;
}

bool Fixed::operator<=(const Fixed& other)
{
    return  this->fp_value <= other.fp_value;
}

bool Fixed::operator==(const Fixed& other)
{
    return  this->fp_value == other.fp_value;
}

bool Fixed::operator!=(const Fixed& other)
{
    return  this->fp_value != other.fp_value;
}

Fixed	&Fixed::operator+(const Fixed &second) {
	this->setRawBits(this->getRawBits() + second.getRawBits());
	return (*this);
}

Fixed	&Fixed::operator-(const Fixed &second) {
	this->setRawBits(this->getRawBits() - second.getRawBits());
	return (*this);
}

Fixed	&Fixed::operator*(const Fixed &second) {
	this->setRawBits(this->getRawBits() * second.getRawBits() >> f_bits);
	return (*this);
}

Fixed	&Fixed::operator/(const Fixed &second) {
	this->setRawBits(this->getRawBits() / second.getRawBits() >> f_bits);
	return (*this);
}

Fixed& Fixed::operator++() {
    ++fp_value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++fp_value;
    return temp;
}

Fixed& Fixed::operator--() {
    --fp_value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --fp_value;
    return temp;
}

/* static Fixed& min(Fixed& first, Fixed& second)
{
    if (first <= second)
        return first;
    else
        return second;
}

static Fixed& min(const Fixed& first, const Fixed& second)
{
    if (first.getRawBits() <= second.getRawBits())
		return ((Fixed &)first);
	return ((Fixed &)second);
} */

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
    if (first >= second)
        return first;
    else
        return second;
}

/* static Fixed& max(const Fixed& first, const Fixed& second)
{
    if (first.getRawBits() >= second.getRawBits())
		return ((Fixed &)first);
	return ((Fixed &)second);
} */