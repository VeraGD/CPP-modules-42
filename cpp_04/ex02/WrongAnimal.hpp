#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <iostream>

class WrongAnimal {
    protected:
    std::string type;
    
    public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& wanimal);
        virtual ~WrongAnimal();
		WrongAnimal& operator=(WrongAnimal& wanimal);
		void makeSound(void) const;
		std::string getType(void) const;
		void setType(std::string type);
};

#endif