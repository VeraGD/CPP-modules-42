#ifndef ICE_H
# define ICE_H

# include <iostream>
# include "AMateria.hpp"

class Ice: public AMateria
{
	protected:

	public:
		Ice();
		Ice(const Ice& ice);
		~Ice();
		Ice& operator=(Ice& ice);
		Ice* clone() const;
		void use(ICharacter& target);
};

#endif