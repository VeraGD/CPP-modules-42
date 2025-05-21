#include "DiamondTrap.hpp"

int main() {
    std::cout << "--------------------------" << std::endl;
    DiamondTrap dt("luisi");

    std::cout << "\n--------------------------" << std::endl;
    dt.whoAmI();

    std::cout << "\n--------------------------" << std::endl;
    dt.attack("pepi");
    dt.takeDamage(30);
    dt.beRepaired(20);

    std::cout << "\n--------------------------" << std::endl;
    return 0;
}