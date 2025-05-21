#include <iostream>
#include <fstream>

std::string ft_replace(std::string to_replace, std::string new_string, std::string line)
{
    std::string new_line = "";
    size_t start = 0;
    size_t end = line.find(to_replace, 0);
    while (end != std::string::npos)
    {
        new_line += line.substr(start, end - start) + new_string;
        start = end + to_replace.size();
        end = line.find(to_replace, start);
    }
    if (start < line.size())
        new_line += line.substr(start, line.length());
    return (new_line);
}

int main(int argc, char **argv) {

    if (argc != 4)
    {
        std::cout << "Invalid arguments" << std::endl;
        return (1);
    }

    std::string line;
    std::string new_line;
    bool primera_linea = true;
    std::ifstream infile(argv[1]);
    std::ofstream	outfile;
    if (!infile.is_open()) {
        std::cerr << "Infile cannot be open" << std::endl;
        return 1;
    }

    outfile.open(((std::string)argv[1] + ".replace").c_str(), std::ios::out);
    if (!outfile.is_open()) {
        std::cout << "Outfile cannot be created" << std::endl;
        infile.close();
        return (1);
    }

    while (std::getline(infile, line))
    {
        if (!primera_linea)
            outfile << "\n";
        new_line = ft_replace(argv[2], argv[3], line);
        outfile << new_line;
        primera_linea = false;
    }
    infile.close();
    outfile.close();
    return (0);
}
  