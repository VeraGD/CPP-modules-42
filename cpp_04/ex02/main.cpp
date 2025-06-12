#include "Dog.hpp"
#include "Cat.hpp"

int	main( void )
{
	//AAnimal test;
	std::cout << "-----------Initilization------------" << std::endl;
	size_t num = 6;
	AAnimal *animals[num];

	for (size_t i = 0; i < num / 2; i++)
		animals[i] = new Cat();
	
	for (size_t i = num / 2; i < num ; i++)
		animals[i] = new Dog();

	std::cout << "-----------Sounds------------" << std::endl;

	for (size_t i = 0; i < num; i++)
		animals[i]->makeSound();

	std::cout << "---------Deconstructors--------------" << std::endl;

	for (size_t i = 0; i < num; i++)
		delete animals[i];

	std::cout << "\n-------------Testing copy constructor for Dog:" << std::endl;
	Dog originalDog;
	Dog copiedDog(originalDog);

	std::cout << "-------------Testing copy assignment operator for Dog:" << std::endl;
	Dog assignedDog;
	assignedDog = originalDog;

	std::cout << "\n---------------Testing copy constructor for Cat:" << std::endl;
	Cat originalCat;
	Cat copiedCat(originalCat);

	std::cout << "----------Testing copy assignment operator for Cat:" << std::endl;
	Cat assignedCat;
	assignedCat = originalCat;

	std::cout << "\n-------------Making sounds to verify everything is working:" << std::endl;
	originalDog.makeSound();
	copiedDog.makeSound();
	assignedDog.makeSound();

	originalCat.makeSound();
	copiedCat.makeSound();
	assignedCat.makeSound();

	std::cout << "---------Deconstructors--------------" << std::endl;
	return 0;
}