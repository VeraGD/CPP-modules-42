#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"

class Cat: public Animal {
    
    public:
        Cat();
		Cat(const Cat& cat);
        ~Cat();
		Cat& operator=(Cat& cat);
		void makeSound(void) const;
};

#endif