#ifndef AANIMAL_H
# define AANIMAL_H

#include <iostream>

class AAnimal {
    protected:
    	std::string type;
		
    public:
		AAnimal();
		AAnimal(const AAnimal& animal);
        virtual ~AAnimal();
		AAnimal& operator=(AAnimal& animal);
		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
};

#endif