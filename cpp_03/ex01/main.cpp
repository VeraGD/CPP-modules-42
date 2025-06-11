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
	scavtrap.beRepaired(10);
    std::cout << "\n------------------------" << std::endl;
    return 0;
}