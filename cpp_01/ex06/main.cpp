#include "Harl.hpp"

int main(int argc, char **argv)
{
    std::string level;
    Harl h;

    if (argc == 2)
    {
        h.filter(argv[1]);
    }
}