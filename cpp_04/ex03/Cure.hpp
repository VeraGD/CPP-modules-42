#ifndef CURE_H
# define CURE_H

# include <iostream>
# include "AMateria.hpp"

class Cure: public AMateria
{
	protected:

	public:
		Cure();
		Cure(const Cure& cure);
		~Cure();
		Cure& operator=(Cure& cure);
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif