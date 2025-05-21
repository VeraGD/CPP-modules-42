#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
    return ;
}

int     PhoneBook::_counter_contacts()
{
    int c = 0;
    for (int i = 0; i < 8; i++)
    {
        if (this->contacts[i].init == 0)
            break ;
        c++;
    }
    return (c);
}

void    PhoneBook::_add_new(Contact contact)
{
    int c = _counter_contacts();
    if (c >= 0 && c <= 7)
    {
        contact.index = c;
        this->contacts[c] = contact;
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            if (this->contacts[i].index == 0)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (j != i)
                    this->contacts[j].index = this->contacts[j].index - 1;
                }
                contact.index = 7;
                this->contacts[i] = contact;
                break ;
            }
        }
    }
}

int    PhoneBook::_len_string(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}

void    PhoneBook::_print_attribute(const std::string& str)
{
    int         spaces;
    std::string s;

    if (str.length() < 10)
    {
        spaces = 10 - str.length();
        while (spaces > 0)
        {
            std::cout << " ";
            spaces--;
        }
        std::cout << str << "|";
    }
    else
    {
        s = str.substr(0, 9);
        std::cout << s << ".|";
    }
}

void    PhoneBook::_print_one_contact(int in)
{
    for (int i = 0; i < 8; i++)
    {
        if (this->contacts[i].init == 1)
        {
            if (this->contacts[i].index == in)
            {
                std::cout << "         " << in << "|";
                _print_attribute(this->contacts[i].first_name);
                _print_attribute(this->contacts[i].last_name);
                _print_attribute(this->contacts[i].nickname);
                std::cout << "" << std::endl;
            }
        }
    }
}

void    PhoneBook::_print_contacts(void)
{
    for (int i = 0; i < 8; i++)
    {
        if (this->contacts[i].init == 1)
            _print_one_contact(i);
        else
            break ;
    }
}

void    PhoneBook::_print_data(char ind)
{
    for (int i = 0; i < 8; i++)
    {
        if (this->contacts[i].index == ind)
        {
            std::cout << "First name: " << this->contacts[i].first_name << std::endl;
            std::cout << "Last name: " << this->contacts[i].last_name << std::endl;
            std::cout << "Nickname: " << this->contacts[i].nickname << std::endl;
            std::cout << "Phone number: " << this->contacts[i].number << std::endl;
            std::cout << "Secret: " << this->contacts[i].secret << std::endl;
            break ;
        }
    }
    std::cout << "Not a valid index" << std::endl;
}

void    PhoneBook::add_contact(void)
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string number;
    std::string secret;

    std::cout << "Input the first name of the contact: ";
    std::cin >> first_name;
    std::cout << "Input the flast name of the contact: ";
    std::cin >> last_name;
    std::cout << "Input the nickname of the contact: ";
    std::cin >> nickname;
    std::cout << "Input the number of the contact: ";
    std::cin >> number;
    std::cout << "Input the darkest secret of the contact: ";
    std::cin >> secret;
    std::cout << std::endl;
    Contact cont(first_name, last_name, nickname, number, secret);
    _add_new(cont);
}

void    PhoneBook::search_contact(void)
{
    int    ind;

    _print_contacts();
    std::cout << std::endl;
    std::cout << "Enter the index of the contact you want more information on: ";
    std::cin >> ind;
    std::cout << std::endl;
    _print_data(ind);
    std::cout << std::endl;
}