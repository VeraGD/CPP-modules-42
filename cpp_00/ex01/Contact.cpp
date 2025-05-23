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

std::string Contact::get_first_name(void)
{
    return first_name;
}

std::string Contact::get_last_name(void)
{
    return last_name;
}

std::string Contact::get_nickname(void)
{
    return nickname;
}

std::string Contact::get_number(void)
{
    return number;
}

std::string Contact::get_secret(void)
{
    return secret;
}

int Contact::get_index(void)
{
    return index;
}

void Contact::set_index(int ind)
{
    index = ind;
}

int Contact::get_init(void)
{
    return init;
}