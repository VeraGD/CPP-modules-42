#include "Contact.hpp"
#include <iostream>

Contact::Contact() {
    this->index = -1;
    this->init = 0;
}

Contact::Contact(std::string first_name, std::string last_name,
    std::string nickname, std::string number, std::string secret) 
{
    this->index = 0;
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->number = number;
    this->secret = secret;
    this->init = 1;
    return ;
}