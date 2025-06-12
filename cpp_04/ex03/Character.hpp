#ifndef CHARACTER_H
# define CHARACTER_H

# include <iostream>
# include <vector>
# include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter &target) = 0;
};

class Character: public ICharacter
{
	private:
		std::string	name;
		AMateria *inventory[4];
		std::vector<AMateria*> toDelete;
	public:
		Character();
		Character(std::string name);
		Character(const Character& chara);
		virtual ~Character();
		Character& operator=(const Character& chara);
		std::string const& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif