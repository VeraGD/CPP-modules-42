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
    int     _counter_contacts(void);
    int     _len_string(char *str);
    void    _print_attribute(const std::string& str);
    void    _print_one_contact(int in);
    void    _add_new(Contact contact);
    void    _print_contacts(void);
    void    _print_data(char ind);
};

#endif