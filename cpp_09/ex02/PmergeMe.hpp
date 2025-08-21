#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <vector>
# include <list>
# include <cstdlib> 
# include <cstring>
#include <cmath>

struct RecursionResult {
    std::vector<int> maximos_finales;                  // la "columna vertebral"
    std::vector<std::vector<int> > minimos_por_nivel;  // los mínimos en cada nivel
};


class PmergeMe
{
	private:
		

	public:
		std::vector<int> vect;
		std::list<int> lis;
		std::vector<int> new_max;
		PmergeMe();
		PmergeMe(char **argv, int argc); // Meter en vect todos lo snumeros y tambien en list
		~PmergeMe();
		void check_params(char **argv, int argc);
		//chequear que son ints y positivos, no decimales
		int get_index(std::vector<int> pos, int to_find);
		void insertar_ordenado(std::vector<int>& vec, int valor);
		RecursionResult split_sort(const std::vector<int>& arr);
		std::vector<int> ordenar_maximos(const std::vector<int>& arr);
		std::vector<int> ordenar_maximos_rec(const std::vector<int>& arr);
		std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right);
		std::vector<int> mergeSort(const std::vector<int>& arr);
		std::vector<int> obtain_max(std::vector<int> arr);
		std::vector<int> obtain_min(std::vector<int> arr);
		void binary_search(std::vector<int> min, std::vector<int> max, std::vector<int> ori);
};

#endif