#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	size_t num = 6;
	Animal *animals[num];

	for (size_t i = 0; i < num / 2; i++)
		animals[i] = new Cat();
	
	for (size_t i = num / 2; i < num ; i++)
		animals[i] = new Dog();

	std::cout << "-----------------------" << std::endl;

	for (size_t i = 0; i < num; i++)
		animals[i]->makeSound();

	std::cout << "-----------------------" << std::endl;

	for (size_t i = 0; i < num; i++)
		delete animals[i];

	/*std::cout << "-----------------------" << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;*/
	return 0;
}