#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc >= 2)
	{
		BitcoinExchange BT;
		BT.read_database("data.csv");
		BT.read_input(argv[1]);
	}
	else
		std::cout << "Error: could not open file." << std::endl;
}