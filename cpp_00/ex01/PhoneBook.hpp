#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook {
public:

    PhoneBook();

    Contact contacts[8];
    void    add_contact(void);
    void    search_contact(void);

private:
    int     counter_contacts(void);
    int     len_string(char *str);
    void    print_attribute(const std::string& str);
    void    print_one_contact(int in);
    void    add_new(Contact contact);
    void    print_contacts(void);
    void    print_data(int ind);
    int     atoi(std::string str);
};

#endif