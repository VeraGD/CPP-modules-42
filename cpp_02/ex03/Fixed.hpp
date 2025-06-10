#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
        private:
            int32_t fp_value;
            static const int f_bits = 8;
        
        public:
            Fixed();
            Fixed(const int value);
            Fixed(const float value);
            Fixed(const Fixed& fixed); // copy constructor
            ~Fixed();
            Fixed& operator=(const Fixed& other);

            //OPERATORS
            bool operator>(const Fixed& other);
            bool operator<(const Fixed& other);
            bool operator>=(const Fixed& other);
            bool operator<=(const Fixed& other);
            bool operator==(const Fixed& other);
            bool operator!=(const Fixed& other);

            Fixed& operator+(const Fixed& other);
            Fixed operator-(const Fixed& other);
            Fixed& operator*(const Fixed &second);
            Fixed& operator/(const Fixed& other);

            Fixed& operator++();
            Fixed operator++(int);
            Fixed& operator--();
            Fixed operator--(int);

            static Fixed& min(Fixed& first, Fixed& second);
            static Fixed& min(const Fixed& first, const Fixed& second);
            static Fixed& max(Fixed& first, Fixed& second);
            static Fixed& max(const Fixed& first, const Fixed& second);

            int getRawBits(void) const;
            void setRawBits(int const raw);
            float toFloat(void) const;
            int toInt(void) const;

            //Fixed& operator<<(Fixed& other);
            //std::ostream& operator<<(const Fixed& f);
};

std::ostream& operator<<(std::ostream&, const Fixed&);

#endif