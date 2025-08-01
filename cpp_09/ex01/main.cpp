#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		RPN r;
		/*std::string* resultado = r.check_input_char(argv[1]);

		if (resultado)
		{
			std::cout << "Resultado completo: " << *resultado << std::endl;
		
			for (size_t k = 0; k < resultado->size(); ++k)
				std::cout << "resultado[" << k << "] = " << (*resultado)[k] << std::endl;
		
			delete resultado;
		}*/

		r.calculate(argv[1]);
	}
	else
		std::cout << "Error: invalid arguments" << std::endl;
}