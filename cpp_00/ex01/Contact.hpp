#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <cstring>

class Contact {
public:

    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string number;
    std::string secret;
    int     index;
    int     init = 0;

    Contact();
    Contact(std::string first_name, std::string last_name,
        std::string nickname, std::string number, std::string secret); 
};

#endif