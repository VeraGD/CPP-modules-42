#include "Cure.hpp"

Cure::Cure()
{
	type = "cure";
	std::cout << "Cure Default constructor" << std::endl;
}

Cure::Cure(const Cure& cure)
{
	std::cout << "Cure copy constructor called" << std::endl;
	type = cure.type;
}

Cure::~Cure()
{
	std::cout << "Cure Deconstructor" << std::endl;
}

Cure& Cure::operator=(const Cure& cure)
{
	if (this != &cure)
	{
		std::cout << "Cure copy assignment operator called" << std::endl;
		type = cure.type;
	}
	return *this;
}

Cure* Cure::clone() const
{
	std::cout << "Cure function clone" << std::endl;
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}