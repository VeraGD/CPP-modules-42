#ifndef HUMAN_A_H
# define HUMAN_A_H

#include <iostream>
#include "Weapon.hpp"
 //#include <cstring>

class HumanA {
	private:
		class Weapon &weapon;
        std::string name;
    public:
        HumanA(std::string name, class Weapon &weapon);
        ~HumanA();
        void    attack(void);
};

#endif