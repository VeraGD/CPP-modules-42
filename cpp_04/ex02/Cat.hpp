#ifndef CAT_H
# define CAT_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: virtual public AAnimal {
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