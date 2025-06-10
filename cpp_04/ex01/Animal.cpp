#include "Animal.hpp"

Animal::Animal(): type("Default")
{
	std::cout << "Animal default constructor" << std::endl;
	return ;
}

Animal::Animal(const Animal& animal)
{
	if (this == &animal)
		return ;
	std::cout << "animal copy constructor called" << std::endl;
	type = animal.type;
}

Animal::~Animal()
{
	std::cout << "Animal deconstructor" << std::endl;
	return ;
}

Animal& Animal::operator=(Animal& animal)
{
	if (this != &animal)
	{
		std::cout << "Animal copy assignment operator called" << std::endl;
		type = animal.type;
	}
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << "I'm an animal" << std::endl;
}

std::string Animal::getType(void) const
{
	return this->type;
}

void Animal::setType(std::string t)
{
	this->type = t;
}