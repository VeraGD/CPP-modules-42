#include "Character.hpp"

Character::Character(): name("default")
{
	for(int i = 0; i < 4; i++)
		inventory[i] = NULL;
	std::cout << "Character Default constructor" << std::endl;
}

Character::Character(std::string name): name(name)
{
	for(int i = 0; i < 4; i++)
		inventory[i] = NULL;
	std::cout << "Character constructor" << std::endl;
}

/*Character::Character(const Character& chara)
{
	// deep copy
	// First delete if he has any materia in inventary
	for(int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
	// copy materia inventory
	for(int i = 0; i < 4; i++)
	{
		inventory[i] = chara.inventory[i];
	}
	// copy name
	name = chara.name;
	// delete toDelete vector
	for (size_t i = 0; i < toDelete.size(); i++)
	{
		delete toDelete[i];
	}
	// copi toDelete
	for (size_t i = 0; i < toDelete.size(); i++)
	{
		toDelete[i] = chara.toDelete[i];
	}
	std::cout << "Character copy constructor" << std::endl;
}*/

Character::Character(const Character& chara)
{
	std::cout << "Character copy constructor" << std::endl;
	name = chara.name;

	for (int i = 0; i < 4; i++)
	{
		if (chara.inventory[i] != NULL)
			inventory[i] = chara.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}


Character::~Character()
{
	// delete materia inventory
	for(int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
	// delete the rest of materia
	for (size_t i = 0; i < toDelete.size(); i++)
	{
		delete toDelete[i];
	}
	std::cout << "Character deconstructor" << std::endl;
}

/*Character& Character::operator=(const Character& chara)
{
	if (this != &chara)
	{
		// deep copy
		// First delete if he has any materia in inventary
		for(int i = 0; i < 4; i++)
		{
			if (inventory[i] != NULL)
				delete inventory[i];
		}
		// copy materia inventory
		for(int i = 0; i < 4; i++)
		{
			inventory[i] = chara.inventory[i];
		}
		// copy name
		name = chara.name;
		// delete toDelete vector
		for (size_t i = 0; i < toDelete.size(); i++)
		{
			delete toDelete[i];
		}
		// copi toDelete
		for (size_t i = 0; i < toDelete.size(); i++)
		{
			toDelete[i] = chara.toDelete[i];
		}
	}
	std::cout << "Character copy operator" << std::endl;
	return *this;
}*/

Character& Character::operator=(const Character& chara)
{
	if (this != &chara)
	{
		std::cout << "Character copy operator" << std::endl;

		name = chara.name;

		// delete inventary
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i] != NULL)
			{
				delete inventory[i];
				inventory[i] = NULL;
			}
		}

		// create new inventary
		for (int i = 0; i < 4; i++)
		{
			if (chara.inventory[i] != NULL)
				inventory[i] = chara.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
		// delete temporal materias
		for (size_t i = 0; i < toDelete.size(); i++)
			delete toDelete[i];
		toDelete.clear();
	}

	return *this;
}

std::string const& Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	for(int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			std::cout << "---- Character: equiped materia of type " << m->getType() << " in inventory " << i << std::endl;
			return ;
		}
	}
	std::cout << "---- Character: inventory full, deleting materia of type " << m->getType() << std::endl;
	delete m;
}

void Character::unequip(int idx)
{
	AMateria *m;

	if (idx < 0 || idx > 3)
		return ;
	if (inventory[idx] != NULL)
	{
		m = inventory[idx];
		for (size_t i = 0; i < toDelete.size(); i++)
		{
			if (toDelete[i] == m)
				return ;
		}
		toDelete.push_back(m);
		std::cout << "---- Character: unequip " << m->getType() << std::endl;
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
        return;
    if (inventory[idx] != NULL)
    {
        inventory[idx]->use(target);
    }
}