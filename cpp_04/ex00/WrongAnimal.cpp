#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("Default")
{
	std::cout << "WrongAnimal default constructor" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wanimal)
{
	if (this == &wanimal)
		return ;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	type = wanimal.type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal deconstructor" << std::endl;
	return ;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& wanimal)
{
	if (this != &wanimal)
	{
		std::cout << "Animal copy assignment operator called" << std::endl;
		type = wanimal.type;
	}
	return *this;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "I'm an s***** animal" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}

void WrongAnimal::setType(std::string t)
{
	this->type = t;
}