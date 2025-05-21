//#include <cstring>
#include <iostream>

int main(void)
{
    std::string s = "HI THIS IS BRAIN";

    std::string *stringPTR = &s;
    std::string &stringREF = s;

    std::cout << "mem address s: " << &s << std::endl;
    std::cout << "mem address ptr: " << stringPTR << std::endl;
    std::cout << "mem address ref: " << &stringREF << std::endl;

    std::cout << "value s: " << s << std::endl;
    std::cout << "value ptr: " << *stringPTR << std::endl;
    std::cout << "value ref: " << stringREF << std::endl;
}