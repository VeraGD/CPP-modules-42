#include "Ice.hpp"

Ice::Ice()
{
	type = "ice";
	std::cout << "Ice Default constructor" << std::endl;
}

Ice::Ice(const Ice& ice)
{
	std::cout << "Ice copy constructor called" << std::endl;
	type = ice.type;
}

Ice::~Ice()
{
	std::cout << "Ice Deconstructor" << std::endl;
}

Ice& Ice::operator=(const Ice& ice)
{
	if (this != &ice)
	{
		std::cout << "Ice copy assignment operator called" << std::endl;
		type = ice.type;
	}
	return *this;
}

Ice* Ice::clone() const
{
	std::cout << "Ice function clone" << std::endl;
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}