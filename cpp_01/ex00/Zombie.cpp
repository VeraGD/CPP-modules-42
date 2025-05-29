#include "Zombie.hpp"

Zombie::Zombie()
{
    return ;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    if (!name.empty())
    {
        std::cout << this->name << " died." << std::endl;
    }
}

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
