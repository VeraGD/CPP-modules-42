#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <vector>
# include <list>
# include <cstdlib> 
# include <cstring>
# include <cmath>
# include <algorithm>
# include <sstream>

struct RecursionResult {
    std::vector<int> maximos_finales;                  // la "columna vertebral"
    std::vector<std::vector<int> > minimos_por_nivel;  // los mínimos en cada nivel
};


class PmergeMe
{
	private:

		std::vector<int> vect;
		std::list<int> lis;
	
		PmergeMe& operator=(const PmergeMe& r);

		void check_params(char **argv, int argc);

		int get_index(std::vector<int> pos, int to_find);
		size_t get_index_list(const std::list<int> &lst, int value);

		std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right);
		std::list<int> merge_list(const std::list<int>& left, const std::list<int>& right);
		
		int search_range(const std::vector<int>& arr, int target, int left, int right);
		std::list<int>::iterator search_range_list(int target, std::list<int>::iterator left, std::list<int>::iterator right);

		std::vector<size_t> ford_johnson_order(size_t n);
		std::list<size_t> ford_johnson_order_list(size_t n);

		size_t index_of(const std::vector<int>& v, int val);
		size_t index_of_list(const std::list<int>& lst, int val);

	public:
		
		PmergeMe();
		PmergeMe(char **argv, int argc);
		PmergeMe(const PmergeMe& r);
		~PmergeMe();

		std::vector<int> mergeSort(const std::vector<int>& arr);
		std::list<int> mergeSort_list(const std::list<int>& lst);

		std::vector<int> obtain_max(std::vector<int> arr);
		std::list<int> obtain_max_list(const std::list<int>& lst);

		std::vector<int> obtain_min(std::vector<int> arr);
		std::list<int> obtain_min_list(const std::list<int>& lst);
		
		void insert_with_jacobsthal(std::vector<int>& mins, std::vector<int>& chain, const std::vector<int>& ori);
		void insert_with_jacobsthal_list(std::list<int>& mins, std::list<int>& chain, const std::list<int>& ori);
	
		std::vector<int> get_vect();
		std::list<int> get_list();
	};

#endif