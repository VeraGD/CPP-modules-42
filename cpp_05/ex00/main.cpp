#include "Bureaucrat.hpp"

int main() {
    std::cout << "--- Valid ceration ---" << std::endl;
    try {
        Bureaucrat b1("Alice", 75);
        std::cout << b1 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Creation test with too high a grade ---" << std::endl;
    try {
        Bureaucrat b2("Bob", 0);  // Invalid
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Creation test with too low a grade ---" << std::endl;
    try {
        Bureaucrat b3("Charlie", 151);  // Invalid
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Valid increment test ---" << std::endl;
    try {
        Bureaucrat b4("Diana", 2);
        std::cout << b4 << std::endl;
        b4.increment_grade();
        std::cout << "After increasing: " << b4 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Out-of-range increment test ---" << std::endl;
    try {
        Bureaucrat b5("Edward", 1);
        std::cout << b5 << std::endl;
        b5.increment_grade();  // it should throw the exception
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Valid decrement test ---" << std::endl;
    try {
        Bureaucrat b6("Fiona", 149);
        std::cout << b6 << std::endl;
        b6.decrement_grade();
        std::cout << "After decrementing: " << b6 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Out-of-range decrement test ---" << std::endl;
    try {
        Bureaucrat b7("George", 150);
        std::cout << b7 << std::endl;
        b7.decrement_grade();  // it should throw the exception
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}