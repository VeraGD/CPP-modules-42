#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
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