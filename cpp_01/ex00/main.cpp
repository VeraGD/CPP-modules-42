#include "Zombie.hpp"

int main(void)
{
    std::cout << "-----------randomChump--------------" << std::endl;
    randomChump("Pepe");
    std::cout << std::endl;

    std::cout << "-----------newZombie--------------" << std::endl;
    Zombie *z = newZombie("Vera");
    z->announce();
    delete z;
}