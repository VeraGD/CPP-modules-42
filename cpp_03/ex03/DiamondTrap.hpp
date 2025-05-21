#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
    private:
        std::string name;
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& d);
        ~DiamondTrap();
        DiamondTrap& operator=(DiamondTrap& d);
        void attack(const std::string& target);
        void whoAmI(void);
};

#endif