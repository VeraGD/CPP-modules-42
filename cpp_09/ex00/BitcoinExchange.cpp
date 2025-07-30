#include "BitcoinExchange.hpp"

void BitcoinExchange::check_date(std::string d)
{

}

void BitcoinExchange::read_database(std::string file)
{
	std::string line;
	std::string date;
	float num;
	int index;

	index = 0;
	std::ifstream infile(file);
	if (!infile.is_open())
	{
        std::cerr << "Infile cannot be open" << std::endl;
        return 1; // Mirar tipo de return y demaas -> ft_error
    }
	while (std::getline(infile, line))
	{
		if (index != 0)
		{
			std::stringstream ss(line);
			std::string date, price;
	
			if (std::getline(ss, date, ',') && std::getline(ss, price))
			{
				// Procesar la línea
				std::cout << "Fecha: " << date << ", Precio: " << price << std::endl;
			}
			else
			{
				std::cout << "Error: " << std::endl; // ft_error
			}
		}
		index = 1;
	}
}