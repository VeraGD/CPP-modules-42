#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	setType("Cat");
	std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wcat)
{
	if (this == &wcat)
		return ;
	std::cout << "Cat copy constructor called" << std::endl;
	type = wcat.type;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat deconstructor" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat& wcat)
{
	if (this != &wcat)
	{
		std::cout << "Cat copy assignment operator called" << std::endl;
		type = wcat.type;
	}
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Muu" << std::endl;
}