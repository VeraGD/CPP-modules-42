#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		PmergeMe p = PmergeMe(argv, argc);

		std::cout << "Before: ";
		for (size_t i = 0; i < p.get_vect().size(); i++)
		{
			std::cout << p.get_vect()[i] << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;

		clock_t start_vect = clock();
		std::vector<int> max = p.obtain_max(p.get_vect());
		std::vector<int> min = p.obtain_min(p.get_vect());
		std::vector<int> sortedArr = p.mergeSort(max);

		//p.binary_search(min, sortedArr, p.vect);
		p.insert_with_jacobsthal(min, sortedArr,  p.get_vect());

		std::cout << "After (vector): ";
		for (size_t i = 0; i < sortedArr.size(); i++)
		{
			std::cout << sortedArr[i] << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;

		clock_t end_vect = clock();
    	double time_vect = double(end_vect - start_vect) / CLOCKS_PER_SEC;
    	std::cout << "Time to process a range of " << sortedArr.size() << " elements with std::vector : " << time_vect << " s" << std::endl;
		std::cout << std::endl;

		clock_t start_list = clock();

		std::list<int> maxl = p.obtain_max_list(p.get_list());
		std::list<int> minl = p.obtain_min_list(p.get_list());
		std::list<int> sortedArrl = p.mergeSort_list(maxl);

		p.insert_with_jacobsthal_list(minl, sortedArrl,  p.get_list());

		std::cout << "After (list): ";
		for (std::list<int>::const_iterator it = sortedArrl.begin(); it != sortedArrl.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;

		clock_t end_list = clock();
    	double time_list = double(end_list - start_list) / CLOCKS_PER_SEC;
    	std::cout << "Time to process a range of " << sortedArrl.size() << " elements with std::list : " << time_list << " s" << std::endl;
	}
	else
	{
		std::cout << "Error: Invalid arguments [./PmergeMe 1 2 3 4 5]" << std::endl;
		std::exit(1);
	}
}