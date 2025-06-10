#include "Brain.hpp"

Brain::Brain()
{
	for (size_t i = 0; i < 100; i++)
		ideas[i] = "I would like to be a cow";
	std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain& b)
{
	if (this == &b)
		return ;
	std::cout << "Brain copy constructor called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		ideas[i] = b.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain deconstructor" << std::endl;
}

Brain& Brain::operator=(Brain& b)
{
	if (this != &b)
	{
		std::cout << "Brain copy assignment operator called" << std::endl;
		for (size_t i = 0; i < 100; i++)
			ideas[i] = b.ideas[i];
	}
	return *this;
}