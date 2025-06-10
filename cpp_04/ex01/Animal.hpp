#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>

class Animal {
    protected:
    	std::string type;
    
    public:
        Animal();
		Animal(const Animal& animal);
        virtual ~Animal();
		Animal& operator=(Animal& animal);
		virtual void makeSound(void) const;
		std::string getType(void) const;
		void setType(std::string type);
};

#endif