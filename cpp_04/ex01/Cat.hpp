#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
    private:
		Brain *brain;
    public:
        Cat();
		Cat(const Cat& cat);
        ~Cat();
		Cat& operator=(Cat& cat);
		void makeSound(void) const;
};

#endif