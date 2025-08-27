#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bt)
{
	dicc = bt.dicc;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &bt)
{
	if (dicc != bt.dicc)
		dicc = bt.dicc;
	return (*this);
}

// Read and check an infile
void BitcoinExchange::read_file(const std::string& file, std::ifstream& infile)
{
	infile.open(file.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: File cannot be open" << std::endl;
		exit(1);
	}
}

// returns 1 if the year is a leap year, and 0 if it is not
int BitcoinExchange::check_leap(std::string d)
{
	std::string year = d.substr(0, 4);
	int y;

	std::stringstream ss(year);
    ss >> y;
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		return 1;
	return 0;
}

// Check if the date is correct, if the month matches the day
int BitcoinExchange::check_month(std::string d)
{
	if (d.size() < 10)
    return 1;
	std::string m31[7] = {"01", "03", "05", "07", "08", "10", "12"};
	std::string m30[4] = {"04", "06", "09", "11"};
	std::string m28 = "02";

	std::string month = d.substr(5, 2);
    std::string day = d.substr(8, 2);
	int dd;
	std::stringstream ss(day);
    ss >> dd;

	int i = 0;
	while (i < 7)
	{
		if (m31[i] == month && (dd > 0 && dd < 32))
			return 0;
		else if (i < 4 && (m30[i] == month && (dd > 0 && dd < 31)))
			return 0;
		else if (month == "02" && check_leap(d) == 1 && dd > 29)
			return 1;
		else if (month == "02" && check_leap(d) == 0 && dd > 28)
			return 1;
		i++;
	}
	return 0;
}

// Check that the date is not later than the current date and that the range is correct.
int BitcoinExchange::check_date_limit(std::string d)
{
	if (d.size() < 10)
    return 1;

    std::string year_str = d.substr(0, 4);
    std::string month_str = d.substr(5, 2);
    std::string day_str = d.substr(8, 2);

    int y, m, dd;
    std::stringstream ss(year_str), sm(month_str), sd(day_str);
    ss >> y;
    sm >> m;
    sd >> dd;

    if (y < 0 || m < 1 || m > 12 || dd < 1 || dd > 31) {
        return 1;
    }

    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);

    int current_y = now->tm_year + 1900;
    int current_m = now->tm_mon + 1;
    int current_d = now->tm_mday;

    if (y > current_y || (y == current_y && m > current_m) || 
        (y == current_y && m == current_m && dd > current_d)) {
        return 1;
    }
    return 0;
}

// check date format YYYY-MM-DD
int BitcoinExchange::check_date_format(std::string d)
{
	
	int i = 0;
	int c = 0;

	if (d.size() < 10)
    return 1;

	while (d[i])
	{
		if ((i >= 0 && i < 4) && (d[i] >= '0' && d[i] <= '9'))
			c++;
		else if ((i == 4 || i == 7) && d[i] == '-')
			c++;
		else if ((i >= 5 && i < 7) && (d[i] >= '0' && d[i] <= '9'))
			c++;
		else if ((i >= 8 && i < 10) && (d[i] >= '0' && d[i] <= '9'))
			c++;
		else if (i > 9)
			return 1;
		i++;
	}
	if (c == 10)
		return 0;
	return 1;
}

// Check price
int BitcoinExchange::check_csv_value(std::string d)
{
	int i = 0;

	if (d.empty())
		return 1;
	while (d[i])
	{
		if ((d[i] < '0' || d[i] > '9') && d[i] != '.')
			return 1;
		i++;
	}
	return 0;
}

// fill the map if the values are okey (just one line)
void BitcoinExchange::fill_map(std::string date, std::string price)
{
	if (check_date_format(date) == 0 && check_month(date) == 0 && check_date_limit(date) == 0)
	{
		if (check_csv_value(price) == 0)
		{
			float fprice;
			std::stringstream ss(price);
			ss >> fprice;
			dicc[date] = fprice;
		}
	}
	else
		std::cout << "Error: Date or price format invalid" << std::endl; // ft_error
}

// read database and check if it's okey
void BitcoinExchange::read_database(std::string file)
{
	std::string line;
	std::string date;
	int index = 0;
	std::ifstream infile;
	read_file(file, infile);

	while (std::getline(infile, line))
	{
		if (index != 0 || (line[0] >= '0' && line[0] <= '9'))
		{
			std::stringstream ss(line);
			std::string date, price;
	
			if (std::getline(ss, date, ',') && std::getline(ss, price))
				fill_map(date, price);
			else
				std::cout << "Error: Line format invalid" << std::endl;
		}
		index = 1;
	}
}

// check the input num value, positive, not empty, just numbers
int BitcoinExchange::check_num_value(std::string d)
{
	int i = 0;
	while(d[i])
	{
		if ((d[i] < '0' || d[i] > '9') && d[i] != '.' && d[i] != '-')
		{
			std::cout << "Error: not a valid number" << std::endl;
			return 1;
		}
		i++;
	}

	float fnum;
	std::stringstream ss(d);
    ss >> fnum;

	if(fnum < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return 1;
	}
	else if (fnum > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return 1;
	}
	return 0;
}

// calculate amount price (value * amount)
float BitcoinExchange::calculate_amount(float n, std::string date)
{
	std::map<std::string, float>::iterator it = dicc.find(date);
	if (it != dicc.end())
		return static_cast<float>(n * it->second);
	else
	{
		const std::string& date_min = dicc.begin()->first;
		if (date < date_min)
		{
			std::cout << "Error: There is no date available in the dictionary to perform the calculation." << std::endl;  // la fecha es menor que la mínima del diccionario
			return -1;
		}
		int y, m, d;
		std::stringstream ss_y(date.substr(0, 4));
		std::stringstream ss_m(date.substr(5, 2));
		std::stringstream ss_d(date.substr(8, 2));
		ss_y >> y;
		ss_m >> m;
		ss_d >> d;
		std::tm t = {};
		t.tm_year = y - 1900;
		t.tm_mon = m - 1;
		t.tm_mday = d - 1;
		std::mktime(&t);
		char buffer[11];
		std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &t);
		return calculate_amount(n, buffer);
	}
}

// check date and num of input file, calculate the amount
void BitcoinExchange::check_perform_amount(std::string date, std::string num)
{
	if (date.length() > 10)
		date = date.substr(0, 10);
	if (check_date_format(date) != 0)
		std::cout << "Error invalid date input format => " << date << std::endl;
	else if (check_month(date) != 0 || check_date_limit(date) != 0)
		std::cout << "Error date does not exist => " << date << std::endl;
	else
	{
		int i = 0;
		if (!num.empty())
		{
			while(num[i] == ' ')
				i++;
			num = num.substr(i);
		}
		if (check_num_value(num) == 0)
		{
			float fnum;
			std::stringstream ss(num);
			ss >> fnum;
			std::cout << date << " => ";
			float c = calculate_amount(fnum, date);
			if (c != -1)
				std::cout <<  num << " = " << c << std::endl;
		}
	}
}

// read and print the results of the input file
void BitcoinExchange::read_input(std::string file)
{
	std::string line;
	int index;

	index = 0;
	std::ifstream infile;
	read_file(file, infile);
	while (std::getline(infile, line))
	{
		if (index != 0 || (line[0] >= '0' && line[0] <= '9'))
		{
			std::stringstream ss(line);
			std::string date, num;
	
			if (std::getline(ss, date, '|') && std::getline(ss, num))
				check_perform_amount(date, num);
			else
				std::cout << "Error bad input => " << line << std::endl;
		}
		index = 1;
	}
}

