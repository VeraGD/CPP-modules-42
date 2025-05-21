#include "HumanA.hpp"

HumanA::HumanA(std::string name, class Weapon &weapon): weapon(weapon)
{
    this->name = name;
}

HumanA::~HumanA()
{
    return ;
}

void    HumanA::attack(void)
{
    std::cout << name << " attacks with their ";
    std::cout << weapon.getType() << std::endl;
}