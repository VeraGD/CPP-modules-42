#include "PmergeMe.hpp"

PmergeMe::PmergeMe() // Meter en vect todos lo snumeros y tambien en list
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

/*void PmergeMe::split_sort(int n_pairs)
{
	for(unsigned int i = 0; i < vect.size() - n_pairs - 1; i = i + n_pairs)
    {
		if (vect[i] > vect[i + n_pairs - 1])
		{
			int a = vect[i];
			vect[i] = vect[i + n_pairs - 1];
			vect[i + 1] = a;
		}
    }
	for (std::vector<int>::const_iterator it = vect.begin(); it != vect.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}*/

/*std::vector<int> PmergeMe::split_sort(std::vector<int> max, std::vector<int> new_max)
{
	// comparo de dos en dos
	for(unsigned int i = 0; i < max.size() - 1; i = i + 2)
	{
		if (max[i] > max[i+1])
			new_max.push_back(max[i]);
		else
			new_max.push_back(max[i+1]);
	}
	if (new_max.size() > 1)
	{
		max = split_sort(max, new_max);
	}
	else
	{
		std::cout << "Maximo: " << max[0] << std::endl;
		std::cout << "Recursivo para abajo" << std::endl;
	}
	return new_max;
}*/

int PmergeMe::get_index(std::vector<int> pos, int to_find)
{
	for (unsigned int i = 0; i < pos.size(); i++)
	{
		if (pos[i] == to_find)
			return i;
	}
	return 0;
}

/*std::vector<int> PmergeMe::split_sort(std::vector<int> max, std::vector<int> min, std::vector<int> pos)
{
    // condicion parada -> que solo hay un maximo. Va hacia atras la recursividad
    if (max.size() <= 1)
	{
		std::cout << "Aqui voy para atras" << std::endl;
		std::cout << "get index: " << get_index(pos, 8) << std::endl;
		std::cout << "Min: " << max[0] << " " << min[0] << " " << pos[0] << std::endl;
		std::cout << "Min: " << max[1] << " " << min[1] << " " << pos[1] << std::endl;
		std::cout << "Min: " << max[2] << " " << min[2] << " " << pos[2] << std::endl;
		std::cout << "Min: " << max[3] << " " << min[3] << " " << pos[3] << std::endl;
		std::cout << "Min: " << max[4] << " " << min[4] << " " << pos[4] << std::endl;
		return max;
	}

    std::vector<int> new_max;

    // saco máximos de los pares y minimos
    for (unsigned int i = 0; i + 1 < max.size(); i += 2)
    {
		pos.push_back(max[i]);
		pos.push_back(max[i+1]);
        if (max[i] > max[i+1])
		{
			new_max.push_back(max[i]);
			min.push_back(max[i+1]);
			//pos.push_back(i+1);
		}
        else
        {
			new_max.push_back(max[i+1]);
			min.push_back(max[i]);
			//pos.push_back(i);
		}
    }

    // si hay un elemento impar al final, se lleva directo
    if (max.size() % 2 != 0)
	{
		new_max.push_back(max.back());
		pos.push_back(max.back());
	}

    // llamada recursiva sobre la nueva lista de máximos
    return split_sort(new_max, min, pos);
}*/

//--------------------------------------------------------------------------------------------------------------------------------------------------
/*RecursionResult PmergeMe::split_sort(const std::vector<int>& arr) {
    RecursionResult result;

    // caso base
    if (arr.size() <= 1) {
        result.maximos_finales = arr;
        return result;
    }

    std::vector<int> maximos;
    std::vector<int> minimos;

    // comparo de dos en dos
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] > arr[i+1]) {
            maximos.push_back(arr[i]);
            minimos.push_back(arr[i+1]);
        } else {
            maximos.push_back(arr[i+1]);
            minimos.push_back(arr[i]);
        }
    }

    // impar → último va a máximos
    if (arr.size() % 2 != 0)
        maximos.push_back(arr.back());

    // llamada recursiva con un vector más pequeño
    RecursionResult rec = split_sort(maximos);

    rec.minimos_por_nivel.insert(rec.minimos_por_nivel.begin(), minimos);

    return rec;
}*/

// RECURSION 8 Y LUEGO PAREJAS
/*RecursionResult PmergeMe::split_sort(const std::vector<int>& arr) {
    RecursionResult result;

    if (arr.size() <= 1) {
        result.maximos_finales = arr;
        return result;
    }

    std::vector<int> maximos;
    std::vector< std::pair<int,int> > minimos;

    // comparo de dos en dos
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] > arr[i+1]) {
            maximos.push_back(arr[i]);
            minimos.push_back(std::make_pair(arr[i+1], arr[i]));
        } else {
            maximos.push_back(arr[i+1]);
            minimos.push_back(std::make_pair(arr[i], arr[i+1]));
        }
    }

    // impar
    if (arr.size() % 2 != 0) {
        maximos.push_back(arr.back());
    }

    // recursión para ordenar los máximos
    RecursionResult rec = split_sort(maximos);

    // unir resultados
    result.maximos_finales = rec.maximos_finales;
    result.pares_minimos = rec.pares_minimos;
    result.pares_minimos.insert(result.pares_minimos.end(), minimos.begin(), minimos.end());

    return result;
}*/

/*void PmergeMe::insertar_ordenado(std::vector<int>& vec, int valor) {
    std::vector<int>::iterator it = vec.begin();
    while (it != vec.end() && *it < valor) {
        ++it;
    }
    vec.insert(it, valor);
}*/


/*RecursionResult PmergeMe::split_sort(const std::vector<int>& arr) {
    RecursionResult result;

    if (arr.size() <= 1) {
        result.maximos_finales = arr;
        return result;
    }

    std::vector<int> maximos;
    std::vector< std::pair<int,int> > minimos;

    // comparo de dos en dos
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] > arr[i+1]) {
            maximos.push_back(arr[i]);
            minimos.push_back(std::make_pair(arr[i+1], arr[i]));
        } else {
            maximos.push_back(arr[i+1]);
            minimos.push_back(std::make_pair(arr[i], arr[i+1]));
        }
    }

    // impar -> último pasa como máximo
    if (arr.size() % 2 != 0) {
        maximos.push_back(arr.back());
    }

    // recursión con los máximos
    RecursionResult rec = split_sort(maximos);

    // ahora los máximos de "rec" ya vienen ordenados
    result.maximos_finales = rec.maximos_finales;

    // insertar en orden los máximos de este nivel
    for (size_t i = 0; i < maximos.size(); i++) {
        insertar_ordenado(result.maximos_finales, maximos[i]);
    }

    // acumular pares mínimos
    result.pares_minimos = rec.pares_minimos;
    result.pares_minimos.insert(result.pares_minimos.end(), minimos.begin(), minimos.end());

    return result;
}*/

/*std::vector<int> PmergeMe::split_sort(const std::vector<int>& arr) {
    // caso base: ya no hay nada que dividir
    if (arr.size() <= 1) {
        return arr;
    }

    std::vector<int> maximos;

    // comparo de dos en dos y guardo el mayor
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] > arr[i+1]) {
            maximos.push_back(arr[i]);
        } else {
            maximos.push_back(arr[i+1]);
        }
    }

    // si hay impar, lo añado tal cual
    if (arr.size() % 2 != 0) {
        maximos.push_back(arr.back());
    }

    // llamada recursiva con los nuevos máximos
    return split_sort(maximos);
}*/

/*std::vector<int> PmergeMe::split_sort(std::vector<int> max, std::vector<int> new_max)
{
    // vector estático que guarda todos los mínimos encontrados
    static std::vector<int> minimos;

    // comparo de dos en dos
    for (unsigned int i = 0; i < max.size() - 1; i += 2)
    {
        if (max[i] > max[i+1]) {
            new_max.push_back(max[i]);
            minimos.push_back(max[i+1]);   // guardo el mínimo
        } else {
            new_max.push_back(max[i+1]);
            minimos.push_back(max[i]);     // guardo el mínimo
        }
    }

    if (new_max.size() > 1)
    {
        max = split_sort(max, new_max);
    }
    else
    {
        std::cout << "Maximo: " << max[0] << std::endl;
        std::cout << "Recursivo para abajo" << std::endl;

        // antes de terminar, puedo usar los mínimos
        std::cout << "Minimos acumulados: ";
        for (size_t i = 0; i < minimos.size(); i++)
            std::cout << minimos[i] << " ";
        std::cout << std::endl;
    }

    return new_max;
}*/

// Función para fusionar dos vectores ordenados
std::vector<int> PmergeMe::merge(const std::vector<int>& left, const std::vector<int>& right)
{
    std::vector<int> result;
    size_t i = 0, j = 0;

    // Comparar elementos de left y right y agregarlos al resultado
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
    // Agregar los elementos restantes
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

// Función MergeSort recursiva
std::vector<int> PmergeMe::mergeSort(const std::vector<int>& arr)
{
    if (arr.size() <= 1)
        return arr;

    int mid = arr.size() / 2;

    // Crear subvectores para la izquierda y la derecha
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    // Ordenar recursivamente y fusionar
    return merge(mergeSort(left), mergeSort(right));
}

std::vector<int> PmergeMe::obtain_max(std::vector<int> arr)
{
    std::vector<int> maximos;
    // comparo de dos en dos
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

std::vector<int> PmergeMe::obtain_min(std::vector<int> arr)
{
    std::vector<int> min;
    // comparo de dos en dos
    for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
        if (arr[i] > arr[i+1])
            min.push_back(arr[i+1]);
		else
            min.push_back(arr[i]);
    }
    return min;
}

/*int search_pair(int min, std::vector<int> ori)
{

}*/


void PmergeMe::binary_search(std::vector<int> min, std::vector<int> max, std::vector<int> ori)
{
	int flag = 0;
	for (size_t i = 0; i < min.size(); i++)
	{
		double j = (pow(2, i) - (pow(-1, i))) / 3;
		if (j < (double)min.size())
			std::cout << "JAC: " << j << std::endl;
		else
		{
			flag = 1;
			break ;
		}
		int i_min = get_index(ori, min[j]);
		int n_max;
		// si es par el minimo
		if (i_min % 2 == 0)
		{
			std::cout << "MAX num: " << ori[i_min + 1] << std::endl;
			
			n_max = get_index(max, ori[i_min + 1]);
			std::cout << "MAX: " << n_max << std::endl;
		}
		else
		{
			std::cout << "MAX num: " << ori[i_min - 1] << std::endl;
			n_max = get_index(max, ori[i_min - 1]);
			std::cout << "MAX: " << n_max << std::endl;
		}
		// Busco el indice de el maximo (pareja) en los maximos

		std::cout << "MIN: " << min[j] << std::endl;
		// selecciono rango
		// SI ES 0
		if (n_max == 0)
		{
			max.insert(max.begin(), min[j]);
			min.erase(min.begin() + j);
		}
		// SI NO ES 0::

		// voy comparando hasta encontrar el sitio (rango)
		// INSERTO EN EL SITIO
	}
	// SI LA FLAG ES 1, VOY PARA ATRAS, HAGO LO MISMO, PERO EN FOR PRINCIPAL INVERSO
}