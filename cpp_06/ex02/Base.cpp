#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	return ;
}

Base *generate(void)
{
	std::srand(std::time(NULL));
	int r = rand() % 3;

	switch(r)
	{
		case 0:
			std::cout << "A created" << std::endl;
			return new A;
		case 1:
			std::cout << "B created" << std::endl;
			return new B;
		default:
			std::cout << "C created" << std::endl;
			return new C;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}
		
void identify(Base &p)
{
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (...) {}

	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (...) {}

	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (...) {}
}