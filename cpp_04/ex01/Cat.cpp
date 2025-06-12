#include "Cat.hpp"

Cat::Cat()
{
	brain = new Brain();
	setType("Cat");
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const Cat& cat)
{
	std::cout << "Dog copy constructor called" << std::endl;
    type = cat.type;
    if (cat.brain)
        brain = new Brain(*cat.brain);
    else
        brain = NULL;
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
		delete brain;
        brain = new Brain(*cat.brain);
	}
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Miiaauuuuu" << std::endl;
}