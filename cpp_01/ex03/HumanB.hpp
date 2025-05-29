#ifndef HUMAN_B_H
# define HUMAN_B_H

#include <iostream>
#include "Weapon.hpp"

class HumanB {
	private:
		class Weapon *weapon;
		std::string name;
    public:
		HumanB();
        HumanB(std::string name);
        ~HumanB();
        void    attack(void);
        void	setWeapon(class Weapon &new_weapon);
};

#endif