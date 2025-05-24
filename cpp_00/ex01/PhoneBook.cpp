#include "PhoneBook.hpp"
#include "Contact.hpp"

#include <string>

PhoneBook::PhoneBook()
{
    return ;
}

int     PhoneBook::counter_contacts()
{
    int c = 0;
    for (int i = 0; i < 8; i++)
    {
        if (this->contacts[i].get_init() == 0)
            break ;
        c++;
    }
    return (c);
}

void    PhoneBook::add_new(Contact contact)
{
    int c = counter_contacts();
    if (c >= 0 && c <= 7)
    {
        contact.set_index(c);
        this->contacts[c] = contact;
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            if (this->contacts[i].get_index() == 0)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (j != i)
                    this->contacts[j].set_index(this->contacts[j].get_index() - 1);
                }
                contact.set_index(7);
                this->contacts[i] = contact;
                break ;
            }
        }
    }
}

int    PhoneBook::len_string(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}

void    PhoneBook::print_attribute(const std::string& str)
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

void    PhoneBook::print_one_contact(int in)
{
    for (int i = 0; i < 8; i++)
    {
        if (this->contacts[i].get_init() == 1)
        {
            if (this->contacts[i].get_index() == in)
            {
                std::cout << "         " << in << "|";
                print_attribute(this->contacts[i].get_first_name());
                print_attribute(this->contacts[i].get_last_name());
                print_attribute(this->contacts[i].get_nickname());
                std::cout << "" << std::endl;
            }
        }
    }
}

void    PhoneBook::print_contacts(void)
{
    for (int i = 0; i < 8; i++)
    {
        if (this->contacts[i].get_init() == 1)
            print_one_contact(i);
        else
            break ;
    }
}

// here CHEAKKKKKKKK
void    PhoneBook::print_data(int ind)
{
    int not_found = 0;
    if (ind  >= 0)
    {
        for (int i = 0; i < 8; i++)
        {
            if (this->contacts[i].get_index() == ind)
            {
                std::cout << "First name: " << this->contacts[i].get_first_name() << std::endl;
                std::cout << "Last name: " << this->contacts[i].get_last_name() << std::endl;
                std::cout << "Nickname: " << this->contacts[i].get_nickname() << std::endl;
                std::cout << "Phone number: " << this->contacts[i].get_number() << std::endl;
                std::cout << "Secret: " << this->contacts[i].get_secret() << std::endl;
                not_found = 1;
                break ;
            }
        }
    }
    if (not_found == 0)
        std::cout << "Not a valid index" << std::endl;
}

int PhoneBook::atoi(std::string str)
{
    if (str.length() == 1 && str[0] >= '0' && str[0] <= '9')
        return str[0] - '0';
    return -1;
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
    std::cout << "Input the last name of the contact: ";
    std::cin >> last_name;
    std::cout << "Input the nickname of the contact: ";
    std::cin >> nickname;
    std::cout << "Input the number of the contact: ";
    std::cin >> number;
    std::cout << "Input the darkest secret of the contact: ";
    std::cin >> secret;
    std::cout << std::endl;
    Contact cont(first_name, last_name, nickname, number, secret);
    add_new(cont);
}

void    PhoneBook::search_contact(void)
{
    std::string    ind;

    print_contacts();
    std::cout << std::endl;
    std::cout << "Enter the index of the contact you want more information on: ";
    std::cin >> ind;
    std::cout << std::endl;
    print_data(atoi(ind));
    std::cout << std::endl;
}
