#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"

class Dog: virtual public Animal {
    
    public:
		Dog();
		Dog(const Dog& dog);
        ~Dog();
		Dog& operator=(Dog& dog);
		void makeSound(void) const;
};

#endif