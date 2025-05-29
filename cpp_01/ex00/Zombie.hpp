#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <cstring>

class Zombie {
    private:
    std::string name;
    
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif