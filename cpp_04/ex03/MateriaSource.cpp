#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
		materias[i] = NULL;
	std::cout << "MateriaSource Default constructor" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& ms)
{
	for(int i = 0; i < 4; i++)
	{
		if (materias[i] != NULL)
			delete materias[i];
	}
	for(int i = 0; i < 4; i++)
	{
		materias[i] = ms.materias[i];
	}
	std::cout << "MateriaSource copy constructor" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < 4; i++)
	{
		if (materias[i] != NULL)
			delete materias[i];
	}
	std::cout << "MateriaSource Deconstructor" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ms)
{
	if (this != &ms)
	{
		std::cout << "MateriaSource assignment operator called" << std::endl;
		for(int i = 0; i < 4; i++)
		{
			if (materias[i] != NULL)
				delete materias[i];
		}
		for(int i = 0; i < 4; i++)
		{
			materias[i] = ms.materias[i];
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* ms)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] == NULL)
		{
			materias[i] = ms;
			std::cout << "---- MateriaSource: learned materia of type " << ms->getType() << " in slot " << i << std::endl;
			return;
		}
	}
	std::cout << "---- MateriaSource: no space to learn materia, deleting it." << std::endl;
	delete ms;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i < 4; i++)
	{
		if (materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return 0;
}