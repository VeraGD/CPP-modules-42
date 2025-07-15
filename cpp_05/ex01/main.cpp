#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat  vera("vera", 70);
	Form        a60("a60", 60, 15);
	Form        a75("a75", 75, 25);

	std::cout << vera << std::endl;
	std::cout << a60 << std::endl;

	std::cout << std::endl;
	std::cout << "--------signForm----------" << std::endl;
	// sign if bureaucrat is high enough, is lower than form
	vera.signForm(a60); // bureaucrat _grade: 70, form garde: 60 -> 70 is lower than 60 -> not signed
	vera.signForm(a75); // bureaucrat _grade: 70, form garde: 75 -> 70 is higher than 75 -> signed

	std::cout << std::endl;
	std::cout << "--------Exception beSigned----------" << std::endl;
	try 
	{
		Bureaucrat  mari("mari", 90); 
		a60.beSigned(mari); // bureaucrat _grade: 90, form garde: 60 -> 90 is lower than 60 -> not signed
	}
	catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------Valid beSigned----------" << std::endl;
	Bureaucrat  pepe("pepe", 40); 
	a60.beSigned(pepe); // bureaucrat _grade: 40, form garde: 60 -> 40 is higher than 60 -> signed
	return 0;
}