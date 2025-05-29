#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>
#include <cstring>

class Weapon {
    private:
    std::string type;
    
    public:
        Weapon();
        Weapon(std::string type);
        ~Weapon();
        std::string getType(void);
        void setType(std::string type);
};

#endif