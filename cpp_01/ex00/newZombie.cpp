#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie* z;

    z = new Zombie(name); // creo en el heap
    return z;
}