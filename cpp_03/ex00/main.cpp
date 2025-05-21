#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap vera = ClapTrap("vera");
    ClapTrap peste = ClapTrap("peste");

    std::cout << "------------------------------" << std::endl;

    peste.attack("vera");
    vera.takeDamage(6);
    std::cout << "------------------------------" << std::endl;
    vera.beRepaired(2);
    std::cout << "------------------------------" << std::endl;
    vera.attack("peste");
    peste.takeDamage(2);
    std::cout << "------------------------------" << std::endl;
    peste.attack("vera");
    vera.takeDamage(8);
    std::cout << "------------------------------" << std::endl;
    vera.beRepaired(3);
    std::cout << "------------------------------" << std::endl;
}