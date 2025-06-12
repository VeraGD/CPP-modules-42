#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	std::cout << "-------------" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << "-------------" << std::endl;
	ICharacter* me = new Character("me");
	AMateria* tmp;
	std::cout << "-------------" << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << "-------------" << std::endl;
	ICharacter* bob = new Character("bob");
	std::cout << "-------------" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "-------------" << std::endl;
	me->unequip(1);
	std::cout << "------------- COPY TESTS -------------" << std::endl;

	Character original("original");
	original.equip(src->createMateria("ice"));
	original.equip(src->createMateria("cure"));

	std::cout << "--------- Creating copy with copy constructor:" << std::endl;
	Character copyConstructed(original);
	copyConstructed.use(0, *bob);

	std::cout << "---------- Creating copy with assignment operator:" << std::endl;
	Character assigned("assigned");
	assigned = original;
	assigned.use(0, *bob);
	std::cout << "-------------" << std::endl;
	delete bob;
	delete me;
	delete src;
	return 0;
}