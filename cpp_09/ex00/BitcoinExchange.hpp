#ifndef BTC_H
# define BTC_H

# include <iostream>
# include <iostream>
# include <fstream>
# include <map>
#include <sstream>

class BitcoinExchange
{
	private:
		std::map<std::string, float> dicc;
		void check_date(std::string d);
	public:
		void read_database(std::string file);

};

#endif