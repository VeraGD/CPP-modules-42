#include "Dog.hpp"
#include "Cat.hpp"

int	main( void )
{
	//const AAnimal* meta = new AAnimal();
	size_t num = 6;
	AAnimal *animals[num];

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
	return 0;
}