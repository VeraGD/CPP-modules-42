#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	ClapTrap::name = "Frag";
    ClapTrap::hitPoint = 100;
    ClapTrap::energyPoint = 100;
    ClapTrap::attackDamage = 30;
    std::cout << "FragTrap Default Constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    ClapTrap::name = name;
    ClapTrap::hitPoint = 100;
    ClapTrap::energyPoint = 100;
    ClapTrap::attackDamage = 30;
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