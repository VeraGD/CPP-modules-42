#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("default_clap_name"), name("default")
{
    ScavTrap temp;

    std::cout << "DiamondTrap Default Constructor" << std::endl;
    hitPoint = FragTrap::getHit();
    energyPoint = temp.getEnergy();
    attackDamage = FragTrap::getAttack();
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), name(name)
{
    ScavTrap	temp;

    hitPoint = FragTrap::getHit();
    energyPoint = temp.getEnergy();
    attackDamage = FragTrap::getAttack();
    std::cout << "DiamondTrap Constructor" << std::endl;
    std::cout << "hit: " << DiamondTrap::hitPoint << " energy: " << DiamondTrap::energyPoint << " attack: " << DiamondTrap::attackDamage << std::endl;
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

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap name: " << this->name;
    std::cout << " ClapTrap name: " << ClapTrap::name << std::endl;
}