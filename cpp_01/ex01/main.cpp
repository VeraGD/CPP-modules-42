#include "Zombie.hpp"

int main(void)
{
    int N = 5;
    int c = 0;
    Zombie *h = zombieHorde(N, "Vera");

    std::cout << "Number of created zombies: " << c << std::endl;

    for (int i = 0; i < N; i++)
    {
        std::cout << "Index of the zombie: " << i << std::endl;
        h[i].announce();
    }
    delete[ ] h;
}