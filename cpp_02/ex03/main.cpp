#include "Point.hpp"

int main(void)
{
	const Point a(0, 0);
	const Point b(0, 4);
	const Point c(4, 0);
	std::cout << "Triangle points: (" << a.getX() << ", " << a.getY() << "), (";
	std::cout << b.getX() << ", " << b.getY() << "), (";
	std::cout << c.getX() << ", " << c.getY() << ")." << std::endl;

	const Point point(1, 2);

	std::cout << "Check if Point: (" << point.getX() << ", " << point.getY() << ") is inside the triangle." << std::endl;
	if (bsp(a, b, c, point) == true)
		std::cout << "\033[32mTRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m" << std::endl;

	const Point point2(2, 2);

	std::cout << "Check if Point: (" << point2.getX() << ", " << point2.getY() << ") is inside the triangle." << std::endl;
	if (bsp(a, b, c, point2) == true)
		std::cout << "\033[32mTRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m" << std::endl;
	
	const Point point3(3, 3);

	std::cout << "Check if Point: (" << point3.getX() << ", " << point3.getY() << ") is inside the triangle." << std::endl;
	if (bsp(a, b, c, point3) == true)
		std::cout << "\033[32mTRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m" << std::endl;
	return (0);
}