#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& frag);
        ~FragTrap();
        FragTrap& operator=(FragTrap& frag);
        void highFivesGuys(void);
};

#endif