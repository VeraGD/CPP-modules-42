#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	ClapTrap::name = "Scav";
    ClapTrap::hitPoint = 100;
    ClapTrap::energyPoint = 50;
    ClapTrap::attackDamage = 20;
    std::cout << "ScavTrap Default Constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    ClapTrap::name = name;
    ClapTrap::hitPoint = 100;
    ClapTrap::energyPoint = 50;
    ClapTrap::attackDamage = 20;
    std::cout << "ScavTrap Constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scav)
{
    if (this == &scav)
		return ;
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	name = scav.name;
    hitPoint = scav.hitPoint;
    energyPoint = scav.energyPoint;
    attackDamage = scav.attackDamage;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Deconstructor" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap& scav)
{
    if (this != &scav)
	{
        std::cout << "ScavTrap Copy assignment operator called" << std::endl;
		name = scav.name;
        hitPoint = scav.hitPoint;
        energyPoint = scav.energyPoint;
        attackDamage = scav.attackDamage;
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (energyPoint > 0 && hitPoint > 0)
    {
        energyPoint -= 1;
        std::cout << "ScavTrap " << this->name << " attacks " << target;
        std::cout << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    }
    else if (energyPoint <= 0 && hitPoint <= 0)
    {
        std::cout << "ScavTrap " << this->name << " cannot attack its target " << target;
        std::cout << ", it has no energy points and no hit points." << std::endl;
    }
    else if (energyPoint <= 0 && hitPoint > 0)
    {
        std::cout << "ScavTrap " << this->name << " cannot attack its target " << target;
        std::cout << ", it has no energy points." << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << this->name << " cannot attack its target " << target;
        std::cout << ", it has no hit points." << std::endl;
    }
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap is Gate keeper mode." << std::endl;
}