#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap Default Constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name)
{
    hitPoint = hitPoint;
    energyPoint = energy;
    attackDamage = att;
    std::cout << "DiamondTrap Constructor" << std::endl;
    std::cout << "hit: " << hitPoint << " energy: " << energyPoint << " attack: " << attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& d)
{
    if (this == &d)
		return ;
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	name = d.name;
    hitPoint = d.hitPoint;
    energyPoint = d.energyPoint;
    attackDamage = d.attackDamage;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Deconstructor" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap& d)
{
    if (this != &d)
	{
        std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
		name = d.name;
        hitPoint = d.hitPoint;
        energyPoint = d.energyPoint;
        attackDamage = d.attackDamage;
    }
    return *this;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap name: " << this->name;
    std::cout << " ClapTrap name: " << ClapTrap::name << std::endl;
}