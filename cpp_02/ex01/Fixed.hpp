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
            //Fixed& operator=(Fixed& other);
            Fixed& operator=(const Fixed& other);
            // copy assigment operator overload

            int getRawBits(void);
            void setRawBits(int const raw);
            float toFloat(void) const;
            int toInt(void) const;

            //Fixed& operator<<(Fixed& other);
            //std::ostream& operator<<(const Fixed& f);
};

std::ostream& operator<<(std::ostream&, const Fixed&);

#endif