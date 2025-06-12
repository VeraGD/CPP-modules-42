#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "---------- Types ---------" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "---------- Sound ---------" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!
	meta->makeSound(); //will output the animal sound!
	std::cout << "---------- Deconstructor ---------" << std::endl;
	delete meta;
	delete i;
	delete j;
	
	std::cout << std::endl;
	std::cout << "---------- Wrong ---------" << std::endl;

	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wi = new WrongCat();
	std::cout << "---------- Type ---------" << std::endl;
	std::cout << wi->getType() << " " << std::endl;
	std::cout << "---------- Sound ---------" << std::endl;
	wi->makeSound(); //will output the wrong animal sound!
	wmeta->makeSound(); //will output the wrong animal sound!
	std::cout << "---------- Deconstructor ---------" << std::endl;
	delete wmeta;
	delete wi;
	return 0;
}