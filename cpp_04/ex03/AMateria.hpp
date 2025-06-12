#ifndef AMATERIA_H
# define AMATERIA_H

# include <iostream>
# include "Character.hpp"

class ICharacter;
class Character;

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(std::string const& type);
		AMateria(const AMateria& materia);
		virtual ~AMateria();
		AMateria& operator=(const AMateria& materia);
		std::string const& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif