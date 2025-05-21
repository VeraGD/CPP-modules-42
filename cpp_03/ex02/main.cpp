#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "--- Creando ClapTrap ---" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("pepe");
    std::cout << "\n--- Creando ScavTrap ---" << std::endl;
    ScavTrap scav("Scavvy");
    scav.attack("Clappy");
    scav.beRepaired(9);
    scav.guardGate();
    std::cout << "\n--- Creando FragTrap ---" << std::endl;
    FragTrap frag("Fraggy");
    frag.attack("Scavvy");
    frag.beRepaired(5);
    frag.highFivesGuys();
    std::cout << "\n------------------------" << std::endl;
    return 0;
}