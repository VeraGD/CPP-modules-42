#include "Point.hpp"

Point::Point(): x(0), y(0) {
}

Point::Point(const Fixed x, const Fixed y): x(x), y(y) {
}

Point::Point(const Point& point): x(point.x), y(point.y) {
}
Point::~Point()
{
    return ;
}

Fixed Point::getX() const
{
    return x;
}

Fixed Point::getY() const
{
    return y;
}

Point& Point::operator=(const Point& p)
{
    if (this != &p)
    {
        this->getX() = p.getX();
        this->getY() = p.getY();
    }
    return *this;
}

Point Point::operator-(const Point& other) const
{
    return Point(this->getX() - other.getX(), this->getY() - other.getY());
}