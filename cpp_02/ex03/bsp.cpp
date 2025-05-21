#include "Point.hpp"
#include <vector>

static float area (const Point a, const Point b, const Point c)
{
	float	area;

	//Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2
	area =	((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()))
			+ (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()))
			+ (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))) / 2;

	if (area >= 0)
		return (area);
	else
		return (area * -1);
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
    float t_area = area(a, b, c);

    float area1 = area(a, b, point);
    float area2 = area(c, a, point);
    float area3 = area(b, c, point);

    if (area1 == 0 || area2 == 0 || area3 == 0)
        return false;
    else if (t_area == area1 + area2 + area3)
        return true;
    else
        return false;
}