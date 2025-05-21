#include "Point.hpp"

/* int main(void)
{
    Point const a = Point(0,0);
    Point const b = Point(0,4);
    Point const c = Point(2,6);
    Point const point = Point(2,2);
	bool t = bsp(a, b, c, point);
    //bool i = TrianglesAreaProach(a, b, c, point);

    if (t == true)
        std::cout << "Esta DENTRO del triangulo" << std::endl;
    else
        std::cout << "Esta FUERA del triangulo" << std::endl;

    if (t == true)
        std::cout << "Esta DENTRO del triangulo AREA" << std::endl;
    else
        std::cout << "Esta FUERA del triangulo AREA" << std::endl;
} */

int main(void)
{
	const Point a(0, 0);
	const Point b(0, 4);
	const Point c(4, 0);
	const Point point(1, 2);

	if (bsp(a, b, c, point) == true)
		std::cout << "\033[32mTRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m" << std::endl;
	return (0);
}