#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <cstring>

class Contact {
private:

    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string number;
    std::string secret;
    int     index;
    int     init = 0;
public:
    Contact();
    Contact(std::string first_name, std::string last_name,
        std::string nickname, std::string number, std::string secret);
    std::string get_first_name(void);
    std::string get_last_name(void);
    std::string get_nickname(void);
    std::string get_number(void);
    std::string get_secret(void);
    int get_index(void);
    void set_index(int ind);
    int get_init(void);
};

#endif