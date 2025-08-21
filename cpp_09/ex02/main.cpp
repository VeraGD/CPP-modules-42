#include "PmergeMe.hpp"

/*int main(int argc, char **argv)
{
	if (argc > 1)
	{
		PmergeMe p = PmergeMe(argv, argc);
		RecursionResult res = p.split_sort(p.vect);

		std::cout << "Maximos finales: ";
		for (std::vector<int>::size_type i = 0; i < res.maximos_finales.size(); ++i) {
			std::cout << res.maximos_finales[i] << " ";
		}
		std::cout << std::endl;

		// Imprimir mínimos por nivel
		for (std::vector< std::vector<int> >::size_type nivel = 0; nivel < res.minimos_por_nivel.size(); ++nivel) {
			std::cout << "Minimos nivel " << nivel << ": ";
			for (std::vector<int>::size_type j = 0; j < res.minimos_por_nivel[nivel].size(); ++j) {
				std::cout << res.minimos_por_nivel[nivel][j] << " ";
			}
			std::cout << std::endl;
		}

		std::vector<int> pos;

		// PRUEBA ORDENAR MAXIMOS
		int max = p.get_index(p.vect, res.maximos_finales[0]);
		pos.push_back(max);
		for (std::vector< std::vector<int> >::size_type nivel = 0; nivel < res.minimos_por_nivel.size(); ++nivel)
		{
			for (std::vector<int>::size_type j = 0; j < res.minimos_por_nivel[nivel].size() + 1; ++j)
			{
				// si es menor que el max -> inserto donde sea
				if (p.get_index(p.vect, res.minimos_por_nivel[nivel][j]) < max)
				{
					std::vector<int>::iterator it = std::lower_bound(pos.begin(), pos.end(), p.get_index(p.vect, res.minimos_por_nivel[nivel][j]));
    				pos.insert(it, p.get_index(p.vect, res.minimos_por_nivel[nivel][j]));
				}
			}
		}
		std::cout << "Maximos fin: ";
		for (std::vector<int>::size_type i = 0; i < pos.size(); ++i) {
			std::cout << pos[i] << " ";
		}
		std::cout << std::endl;

	}
	else
	{
		std::cout << "Error: Invalid arguments [./PmergeMe 1 2 3 4 5]" << std::endl;
		std::exit(1);
	}
}*/

#include <iostream>
#include <vector>



int main(int argc, char **argv)
{
	if (argc > 1)
	{
		PmergeMe p = PmergeMe(argv, argc);
		std::vector<int> max = p.obtain_max(p.vect);
		std::vector<int> min = p.obtain_min(p.vect);
		std::vector<int> sortedArr = p.mergeSort(max);

		std::cout << "Maximos ordenados: ";
		for (size_t i = 0; i < sortedArr.size(); i++)
		{
			std::cout << sortedArr[i] << " ";
		}
		std::cout << std::endl;

		p.binary_search(min, sortedArr, p.vect);

	}
	else
	{
		std::cout << "Error: Invalid arguments [./PmergeMe 1 2 3 4 5]" << std::endl;
		std::exit(1);
	}
}