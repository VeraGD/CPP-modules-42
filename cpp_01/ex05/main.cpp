#include "Harl.hpp"

/*int main()
{
    std::string level;
    Harl h;

    level = "hola";
    while(1)
    {
        // INPUT THE LEVEL TO SEE HOW HARL COMPLAINS
        std::cout << "Input a level (DEBUG, INFO, WARNING, ERROR) or EXIT: ";
        std::cin >> level;
        if (level.compare("EXIT") == 0)
        {
            std::cout << "Exit" << std::endl;
            break ;
        }
        h.complain(level);
    }
}*/

int	main(void)
{
	Harl	h;

	h.complain("INFO");
	std::cout << "-----------------------" << std::endl;
	h.complain("ERROR");
	std::cout << "-----------------------" << std::endl;
	h.complain("WARNING");
	std::cout << "-----------------------" << std::endl;
	h.complain("DEBUG");
	std::cout << "-----------------------" << std::endl;
	h.complain("Whatever");
}