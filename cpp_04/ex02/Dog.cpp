#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const Dog& dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
    type = dog.type;
    if (dog.brain)
        brain = new Brain(*dog.brain);
    else
        brain = NULL;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog deconstructor" << std::endl;
}

Dog& Dog::operator=(Dog& dog)
{
	if (this != &dog)
	{
		std::cout << "Cat copy assignment operator called" << std::endl;
		type = dog.type;
		delete brain;
        brain = new Brain(*dog.brain);
	}
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Guauuuu Guauuu" << std::endl;
}