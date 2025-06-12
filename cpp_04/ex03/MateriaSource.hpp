#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include <iostream>
# include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource: public IMateriaSource
{
	private:
		AMateria *materias[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& ms);
		~MateriaSource();
		MateriaSource& operator=(const MateriaSource& ms);
		void learnMateria(AMateria* ms);
		AMateria* createMateria(std::string const & type);
};

#endif
