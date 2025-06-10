#include "Cat.hpp"

Cat::Cat()
{
	brain = new Brain();
	type = "Cat";
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const Cat& cat)
{
	if (this == &cat)
		return ;
	std::cout << "Cat copy constructor called" << std::endl;
	type = cat.type;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat deconstructor" << std::endl;
}

Cat& Cat::operator=(Cat& cat)
{
	if (this != &cat)
	{
		std::cout << "Cat copy assignment operator called" << std::endl;
		type = cat.type;
	}
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Miiaauuuuu" << std::endl;
}