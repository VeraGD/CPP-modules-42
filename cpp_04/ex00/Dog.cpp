#include "Dog.hpp"

Dog::Dog()
{
	setType("Dog");
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const Dog& dog)
{
	if (this == &dog)
		return ;
	std::cout << "Dog copy constructor called" << std::endl;
	type = dog.type;
}

Dog::~Dog()
{
	std::cout << "Dog deconstructor" << std::endl;
}

Dog& Dog::operator=(Dog& dog)
{
	if (this != &dog)
	{
		std::cout << "Cat copy assignment operator called" << std::endl;
		type = dog.type;
	}
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Guauuuu Guauuu" << std::endl;
}