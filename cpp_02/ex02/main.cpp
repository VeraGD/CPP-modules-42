#include "Fixed.hpp"

int main( void ) {

	Fixed a; // equal to 0
	Fixed b(Fixed( 5.05f ) * Fixed( 2 ));

	std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << b << std::endl;
	std::cout << --b << std::endl;
	std::cout << b << std::endl;
	std::cout << b-- << std::endl;
	std::cout << b << std::endl;
	std::cout << "-------------------------------------" << std::endl;
    std::cout << "max: " << Fixed::max(a, b) << std::endl;
	std::cout << "min: " << Fixed::min(a, b) << std::endl;
	const Fixed aa(89);
	const Fixed bb(7);
	std::cout << "max: " << Fixed::max(aa, bb) << std::endl;
	std::cout << "min: " << Fixed::min(aa, bb) << std::endl;
	std::cout << "-------------------------------------" << std::endl;
    Fixed c = Fixed(4) + Fixed(2);
	std::cout << "+: " << c << std::endl;
	Fixed d = Fixed(4) - Fixed(2);
	std::cout << "-: " << d << std::endl;
	Fixed e = Fixed(4) * Fixed(2);
	std::cout << "*: " << e << std::endl;
	Fixed f = Fixed(4) / Fixed(2);
	std::cout << "/: " << f << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	a = 2;
	b = 1;
	if (b <= a)
		std::cout << "b es menor igual" << std::endl;
	if (b < a)
		std::cout << "b es menor" << std::endl;
	if (a >= b)
		std::cout << "a es mayor igual" << std::endl;
	if (a > b)
		std::cout << "a es mayor" << std::endl;
	if (a != b)
		std::cout << "son diferentes" << std::endl;
	Fixed h = Fixed(a);
	if (a == h)
		std::cout << "son iguales" << std::endl;
	return 0;
}