#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
    protected:
        static const int att = 30;
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& frag);
        ~FragTrap();
        FragTrap& operator=(FragTrap& frag);
        void highFivesGuys(void);
};

#endif