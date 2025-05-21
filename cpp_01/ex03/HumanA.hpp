#ifndef HUMAN_A_H
# define HUMAN_A_H

#include <iostream>
#include "Weapon.hpp"
 //#include <cstring>

class HumanA {
    public:
        class Weapon &weapon;
        std::string name;
        HumanA(std::string name, class Weapon &weapon);
        ~HumanA();
        void    attack(void);
};

#endif