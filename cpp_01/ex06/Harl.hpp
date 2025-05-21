#ifndef HARL_H
# define HARL_H

#include <iostream>
#include <cstring>

class Harl {
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        void complain(std::string level);
    
    public:
        Harl();
        ~Harl();
        void filter(std::string level);
};

#endif