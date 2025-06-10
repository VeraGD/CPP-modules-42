#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(): type("default")
{
	std::cout << "AMateria Default constructor" << std::endl;
}

AMateria::AMateria(std::string const& type): type(type)
{
	std::cout << "AMateria constructor" << std::endl;
}

AMateria::AMateria(const AMateria& materia)
{
	if (this == &materia)
		return ;
	std::cout << "AMateria copy constructor called" << std::endl;
	type = materia.type;
}

AMateria::~AMateria()
{
	std::cout << "AMateria deconstructor" << std::endl;
}

AMateria& AMateria::operator=(AMateria& materia)
{
	if (this != &materia)
	{
		std::cout << "AMateria copy assignment operator called" << std::endl;
		type = materia.type;
	}
	return *this;
}

const std::string &AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria " << type << " target " << target.getName() << std::endl;
}