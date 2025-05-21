#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
    char    cmd[512];

    (void)argv;
    if (argc == 1)
    {
        PhoneBook pb;
        while(1)
        {
            std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
            std::cout << "";
            std::cin >> cmd;
            std::cout << std::endl;
            if (strcmp(cmd, "ADD") == 0)
                pb.add_contact();
            else if (strcmp(cmd, "SEARCH") == 0)
                pb.search_contact();
            else if (strcmp(cmd, "EXIT") == 0)
                break ;
            else
            {
                std::cout << "Enter a valid comand" << std::endl;
                std::cout << std::endl;
            }
        }
    }
    return 0;
}