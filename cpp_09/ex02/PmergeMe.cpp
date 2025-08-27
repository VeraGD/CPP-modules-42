#include "PmergeMe.hpp"


PmergeMe::PmergeMe() 
{
	
}

PmergeMe::PmergeMe(char **argv, int argc)
{
	check_params(argv, argc);
	for (int i = 1; i < argc; i++)
	{
		vect.push_back(std::atoi(argv[i]));
		lis.push_back(std::atoi(argv[i]));
	}
}

PmergeMe::PmergeMe(const PmergeMe& r)
{
    vect = r.vect;
    lis  = r.lis;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& r)
{
    if (this != &r)
    {
        vect = r.vect;
        lis  = r.lis;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

//chequear que son ints y positivos, no decimales
void PmergeMe::check_params(char **argv, int argc)
{
	for (int i = 1; i < argc; i++)
	{
		for (size_t j = 0; j < std::strlen(argv[i]); j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				std::cout << "Error: Not a valid int secuence" << std::endl;
				std::exit(1);
			}
		}
	}
}

std::vector<int> PmergeMe::get_vect()
{
    return vect;
}

std::list<int> PmergeMe::get_list()
{
    return lis;
}


int PmergeMe::get_index(std::vector<int> pos, int to_find)
{
	for (unsigned int i = 0; i < pos.size(); i++)
	{
		if (pos[i] == to_find)
			return i;
	}
	return 0;
}

size_t PmergeMe::get_index_list(const std::list<int> &lst, int value)
{
    size_t idx = 0;
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it, ++idx) {
        if (*it == value) return idx;
    }
    return idx;
}

// Función para fusionar dos vectores ordenados
std::vector<int> PmergeMe::merge(const std::vector<int>& left, const std::vector<int>& right)
{
    std::vector<int> result;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size())
	{
        if (left[i] < right[j])
		{
            result.push_back(left[i]);
            i++;
        }
		else
		{
            result.push_back(right[j]);
            j++;
        }
    }
    while (i < left.size())
	{
        result.push_back(left[i]);
        i++;
    }
    while (j < right.size())
	{
        result.push_back(right[j]);
        j++;
    }

    return result;
}

std::list<int> PmergeMe::merge_list(const std::list<int>& left, const std::list<int>& right)
{
    std::list<int> result;
    std::list<int>::const_iterator it_left = left.begin();
    std::list<int>::const_iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end()) {
        if (*it_left < *it_right) {
            result.push_back(*it_left++);
        } else {
            result.push_back(*it_right++);
        }
    }
    while (it_left != left.end()) result.push_back(*it_left++);
    while (it_right != right.end()) result.push_back(*it_right++);

    return result;
}

// Función MergeSort recursiva
std::vector<int> PmergeMe::mergeSort(const std::vector<int>& arr)
{
    if (arr.size() <= 1)
        return arr;

    int mid = arr.size() / 2;

    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    return merge(mergeSort(left), mergeSort(right));
}

std::list<int> PmergeMe::mergeSort_list(const std::list<int>& lst)
{
    if (lst.size() <= 1) return lst;

    std::list<int>::const_iterator mid_it = lst.begin();
    std::advance(mid_it, lst.size() / 2);

    std::list<int> left(lst.begin(), mid_it);
    std::list<int> right(mid_it, lst.end());

    return merge_list(mergeSort_list(left), mergeSort_list(right));
}

std::vector<int> PmergeMe::obtain_max(std::vector<int> arr)
{
    std::vector<int> maximos;
    for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
        if (arr[i] > arr[i+1])
            maximos.push_back(arr[i]);
		else
            maximos.push_back(arr[i+1]);
    }
    if (arr.size() % 2 != 0)
        maximos.push_back(arr.back());
    return maximos;
}

std::list<int> PmergeMe::obtain_max_list(const std::list<int>& lst)
{
    std::list<int> maximos;
    std::list<int>::const_iterator it = lst.begin();

    while (it != lst.end()) {
        int first = *it++;
        if (it == lst.end()) {
            maximos.push_back(first);
            break;
        }
        int second = *it++;
        maximos.push_back(std::max(first, second));
    }
    return maximos;
}
std::vector<int> PmergeMe::obtain_min(std::vector<int> arr)
{
    std::vector<int> min;
    for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
        if (arr[i] > arr[i+1])
            min.push_back(arr[i+1]);
		else
            min.push_back(arr[i]);
    }
    return min;
}

std::list<int> PmergeMe::obtain_min_list(const std::list<int>& lst)
{
    std::list<int> minimos;
    std::list<int>::const_iterator it = lst.begin();

    while (it != lst.end()) {
        int first = *it++;
        if (it == lst.end()) {
            break;
        }
        int second = *it++;
        minimos.push_back(std::min(first, second));
    }
    return minimos;
}

// Búsqueda binaria estilo lower_bound en rango [left, right)
int PmergeMe::search_range(const std::vector<int>& arr, int target, int left, int right)
{
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (target <= arr[mid])
            right = mid;
        else
            left  = mid + 1;
    }
    return left;
}

std::list<int>::iterator PmergeMe::search_range_list(int target, std::list<int>::iterator left, std::list<int>::iterator right)
{
    while (left != right)
    {
        std::list<int>::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);
        if (target <= *mid)
            right = mid;
        else
            left = ++mid;
    }
    return left;
}

// Generar orden de índices usando números de Jacobsthal
std::vector<size_t> PmergeMe::ford_johnson_order(size_t n) {
    std::vector<size_t> order;
    size_t Jprev = 0;
    size_t J = 1;

    while (J < n) {
        size_t t = J;
        while (t-- > Jprev) {
            order.push_back(t);
        }
        size_t Jnext = J + 2 * Jprev;
        Jprev = J;
        J = Jnext;
    }
    size_t t = n;
    while (t-- > Jprev) {
        order.push_back(t);
    }
    return order;
}

std::list<size_t> PmergeMe::ford_johnson_order_list(size_t n)
{
    std::list<size_t> order;
    size_t Jprev = 0, J = 1;

    while (J < n) {
        size_t t = J;
        while (t-- > Jprev) order.push_back(t);
        size_t Jnext = J + 2 * Jprev;
        Jprev = J;
        J = Jnext;
    }
    size_t t = n;
    while (t-- > Jprev) order.push_back(t);
    return order;
}

// Busca el índice de un valor en un vector
size_t PmergeMe::index_of(const std::vector<int>& v, int val)
{
    std::vector<int>::const_iterator it = std::find(v.begin(), v.end(), val);
    return static_cast<size_t>(it - v.begin());
}

size_t PmergeMe::index_of_list(const std::list<int>& lst, int val)
{
    size_t idx = 0;
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it, ++idx) {
        if (*it == val) return idx;
    }
    return idx;
}

void PmergeMe::insert_with_jacobsthal(std::vector<int>& mins, std::vector<int>& chain, const std::vector<int>& ori)
{
    std::vector<size_t> ins_order = ford_johnson_order(mins.size());

    for (size_t k_i = 0; k_i < ins_order.size(); ++k_i) {
        size_t k = ins_order[k_i];
        int m = mins[k];

        size_t pos_in_ori = index_of(ori, m);
        int pair_max;
        if (pos_in_ori % 2 == 0)
            pair_max = ori[pos_in_ori + 1];
        else
            pair_max = ori[pos_in_ori - 1];

        size_t idx_max_in_chain = index_of(chain, pair_max);

        int insert_pos = search_range(chain, m, 0, static_cast<int>(idx_max_in_chain) + 1);
        chain.insert(chain.begin() + insert_pos, m);
    }
}

static std::list<int>::iterator lower_bound_range_list(int value, std::list<int>::iterator first, std::list<int>::iterator last)
{
    for (std::list<int>::iterator it = first; it != last; ++it) {
        if (value <= *it) return it;
    }
    return last;
}

void PmergeMe::insert_with_jacobsthal_list(std::list<int>& mins, std::list<int>& chain, const std::list<int>& ori)     
{
    std::list<size_t> ins_order = ford_johnson_order_list(mins.size());

    for (std::list<size_t>::const_iterator oit = ins_order.begin();
         oit != ins_order.end(); ++oit)
    {
        size_t k = *oit;

        std::list<int>::iterator it_m = mins.begin();
        std::advance(it_m, k);
        int m = *it_m;

        size_t pos_in_ori = index_of_list(ori, m);

        int pair_max;
        std::list<int>::const_iterator it_ori = ori.begin();
        if (pos_in_ori % 2 == 0)
            std::advance(it_ori, pos_in_ori + 1);
        else
            std::advance(it_ori, pos_in_ori - 1);
        pair_max = *it_ori;

        size_t idx_pair = index_of_list(chain, pair_max);
        std::list<int>::iterator it_pair = chain.begin();
        std::advance(it_pair, idx_pair);

        std::list<int>::iterator one_past_pair = it_pair;
        ++one_past_pair;

        std::list<int>::iterator pos = lower_bound_range_list(m, chain.begin(), one_past_pair);

        chain.insert(pos, m);
    }
}