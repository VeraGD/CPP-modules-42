#ifndef BTC_H
# define BTC_H

# include <iostream>
# include <iostream>
# include <fstream>
# include <map>
# include <sstream>
# include <ctime>
# include <cstring>
# include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, float> dicc;

		BitcoinExchange(const BitcoinExchange &bt);
		BitcoinExchange& operator=(const BitcoinExchange &bt);
		void read_file(const std::string& file, std::ifstream& infile);
		int check_leap(std::string d);
		int check_month(std::string d);
		int check_date_limit(std::string d);
		int check_date_format(std::string d);
		int check_csv_value(std::string d);
		int check_num_value(std::string d);
		void fill_map(std::string date, std::string price);
		float calculate_amount(float n, std::string date);
		void check_perform_amount(std::string date, std::string num);

	public:
		BitcoinExchange();
		~BitcoinExchange();
		void read_database(std::string file);
		void read_input(std::string file);

};

#endif