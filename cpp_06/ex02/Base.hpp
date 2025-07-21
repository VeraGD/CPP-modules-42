#ifndef BASE_H
# define BASE_H

# include <iostream>
# include <cstdlib>
# include <ctime>

class Base
{
	private:
		
	public:
		virtual ~Base();
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif