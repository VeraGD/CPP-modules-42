#include "HumanB.hpp"

HumanB::HumanB()
{
	weapon = NULL;
}

HumanB::HumanB(std::string name)
{
    this->name = name;
}

HumanB::~HumanB()
{
    return ;
}

void	HumanB::setWeapon(Weapon &new_weapon)
{
	weapon = &new_weapon;
}

void    HumanB::attack(void)
{
    std::cout << name << " attacks with their ";
    std::cout << weapon->getType() << std::endl;
}