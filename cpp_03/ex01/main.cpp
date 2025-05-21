#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "--- Creando ClapTrap ---" << std::endl;
    ClapTrap claptrap("CLTP");
    claptrap.attack("pepe");
    std::cout << "\n--- Creando ScravTrap ---" << std::endl;
    ScavTrap scavtrap("SCVT");
    scavtrap.attack("pepa");
    scavtrap.takeDamage(20);
    scavtrap.guardGate();
    std::cout << "\n------------------------" << std::endl;
    ScavTrap mari("mari");
    scavtrap = mari;
    scavtrap.takeDamage(20);
    std::cout << "\n------------------------" << std::endl;
    ScavTrap juani(mari);
    juani.takeDamage(30);
    std::cout << "\n------------------------" << std::endl;
    return 0;
}