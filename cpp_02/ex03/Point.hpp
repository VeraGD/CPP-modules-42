#ifndef Point_H
# define Point_H

#include "Fixed.hpp"

class Point {

    private:
        const Fixed x;
        const Fixed y;
    public:
        Point();
        Point(const Fixed x, const Fixed y);
        Point(const Point& point);
        ~Point();
        Point& operator=(const Point& p);
        Point operator-(const Point& other) const;
        Fixed getX() const;
        Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

bool    TrianglesAreaProach(const Point a, const Point b, const Point c, const Point p);

#endif