#ifndef DOG_H
# define DOG_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: virtual public AAnimal {
    private:
		Brain *brain;
    public:
		Dog();
		Dog(const Dog& dog);
        ~Dog();
		Dog& operator=(Dog& dog);
		void makeSound(void) const;
};

#endif