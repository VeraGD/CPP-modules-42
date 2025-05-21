#include "Harl.hpp"

Harl::Harl()
{
    return ;
}
Harl::~Harl()
{
    return ;
}

void Harl::debug(void)
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my ";
    std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger.";
    std::cout << " I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. ";
    std::cout << "You didn’t put enough bacon in my burger! ";
    std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. ";
    std::cout << "I’ve been coming for years, whereas ";
    std::cout << " you started working here just last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now.";
    std::cout << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*function_list[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string     level_list[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int i;
    for (i = 0; i < 4; i++)
    {
        if (level == level_list[i])
        {
            (this->*function_list[i])();
            return ;
        }
    }
    std::cout << "[Probably complaining about insignificant problems]" << std::endl;
}

void Harl::filter(std::string level)
{
    std::string     level_list[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int i = 0;
    while (level != level_list[i] && i < 4)
        i++;
    switch (i) {
        case 0:
            complain("DEBUG");
        case 1:
            complain("INFO");
        case 2:
            complain("WARNING");
        case 3:
            complain("ERROR");
            break ;
        default:
            complain("?");
      }
}