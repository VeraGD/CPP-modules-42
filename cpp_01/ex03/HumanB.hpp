#ifndef HUMAN_B_H
# define HUMAN_B_H

#include <iostream>
#include "Weapon.hpp"
 //#include <cstring>

class HumanB {
    public:
        class Weapon *weapon;
        std::string name;
        HumanB(std::string name);
        ~HumanB();
        void    attack(void);
        void	setWeapon(class Weapon &new_weapon);
};

#endif