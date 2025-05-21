#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
    protected:
        static const int energy = 50;
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& scav);
        ~ScavTrap();
        ScavTrap& operator=(ScavTrap& scav);
        void guardGate(void);
        void attack(const std::string& target);
};

#endif