#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Animal default constructor" << std::endl;
	return ;
}

AAnimal::AAnimal(const AAnimal& animal)
{
	if (this == &animal)
		return ;
	std::cout << "animal copy constructor called" << std::endl;
	type = animal.type;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal deconstructor" << std::endl;
	return ;
}

AAnimal& AAnimal::operator=(AAnimal& animal)
{
	if (this != &animal)
	{
		std::cout << "Animal copy assignment operator called" << std::endl;
		type = animal.type;
	}
	return *this;
}

void AAnimal::makeSound(void) const
{
	std::cout << "I'm an animal" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return this->type;
}