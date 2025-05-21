#include <iostream>
#include <cctype>

/* the toupper function works when passed an int as argument,
    that's why I cast it to char.
    /n only at the final.
 */
int main(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (argv[i])
        {
            j = 0;
            while (argv[i][j])
            {
                std::cout << (char)toupper(argv[i][j]);
                j++;
            }
            //std::cout << " ";
            i++;
        }
        std::cout << std::endl;
    }
    return (0);
}