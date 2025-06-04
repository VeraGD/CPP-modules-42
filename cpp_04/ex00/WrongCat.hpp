#ifndef WRONGCAT_H
# define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat: virtual public WrongAnimal {
    
    public:
		WrongCat();
		WrongCat(const WrongCat& wcat);
        ~WrongCat();
		WrongCat& operator=(WrongCat& wcat);
		void makeSound(void) const;
};

#endif