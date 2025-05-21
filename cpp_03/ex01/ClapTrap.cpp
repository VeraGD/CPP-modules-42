#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap Default Constructor called." << std::endl;
}

// Evita doble inicialización, Obligatorio para miembros const o referencias.
// Más explícito y claro para constructores personalizados.
ClapTrap::ClapTrap(std::string name): name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
    std::cout << "ClapTrap Constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clap)
{
    if (this == &clap)
		return ;
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	name = clap.name;
    hitPoint = clap.hitPoint;
    energyPoint = clap.energyPoint;
    attackDamage = clap.attackDamage;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Deconstructor called." << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap& clap)
{
    if (this != &clap)
	{
		std::cout << "ClapTrap Copy assignment operator called" << std::endl;
		name = clap.name;
        hitPoint = clap.hitPoint;
        energyPoint = clap.energyPoint;
        attackDamage = clap.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (energyPoint > 0 && hitPoint > 0)
    {
        energyPoint -= 1;
        std::cout << "ClapTrap " << this->name << " attacks " << target;
        std::cout << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    }
    else if (energyPoint <= 0 && hitPoint <= 0)
    {
        std::cout << "ClapTrap " << this->name << " cannot attack its target " << target;
        std::cout << ", it has no energy points and no hit points." << std::endl;
    }
    else if (energyPoint <= 0 && hitPoint > 0)
    {
        std::cout << "ClapTrap " << this->name << " cannot attack its target " << target;
        std::cout << ", it has no energy points." << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " cannot attack its target " << target;
        std::cout << ", it has no hit points." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    int lose;
    if ((unsigned int)hitPoint > amount)
            lose = amount;
        else
            lose = hitPoint;
    if(hitPoint > 0)
    {
        while (hitPoint >= 0 && amount > 0)
        {
            if (hitPoint != 0)
                hitPoint--;
            amount--;
        }
        std::cout << "ClapTrap " << this->name << " was attacked and lose " << lose;
        std::cout << " hit points, it has " << hitPoint << " points of life." <<  std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " cannot be attacked, it doesn't have enough life.";
        std::cout << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoint > 0 && hitPoint > 0)
    {
        hitPoint += amount;
        energyPoint -= 1;
        std::cout << "ClapTrap " << this->name << " repairs itself " << amount;
        std::cout << " hit points, now it has " << hitPoint << " points of life." << std::endl;
    }
    else if (energyPoint <= 0 && hitPoint <= 0)
    {
        std::cout << "ClapTrap " << this->name << " cannot repair itself, ";
        std::cout << "it has no energy points and no hit points." << std::endl;
    }
    else if (energyPoint <= 0 && hitPoint > 0)
    {
        std::cout << "ClapTrap " << this->name << " cannot repair itself, ";
        std::cout << "it has no energy points." << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " cannot repair itself, ";
        std::cout << "it has no hit points." << std::endl;
    }
}
