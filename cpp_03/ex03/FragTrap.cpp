#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap Default Constructor called." << std::endl;
    hitPoint = 100;
    energyPoint = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->name = name;
    hitPoint = 100;
    energyPoint = 100;
    attackDamage = 30;
    std::cout << "FragTrap Constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& frag)
{
    if (this == &frag)
		return ;
	std::cout << "FragTrap Copy constructor called" << std::endl;
	name = frag.name;
    hitPoint = frag.hitPoint;
    energyPoint = frag.energyPoint;
    attackDamage = frag.attackDamage;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Deconstructor" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap& frag)
{
    if (this != &frag)
	{
		std::cout << "FragTrap Copy assignment operator called" << std::endl;
		name = frag.name;
        hitPoint = frag.hitPoint;
        energyPoint = frag.energyPoint;
        attackDamage = frag.attackDamage;
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a high-five!" << std::endl;
}