#ifndef FIXED_H
# define FIXED_H

#include <iostream>
// #include <cstring>

class Fixed {
        private:
            int fp_value = 0;
            static const int f_bits = 8;
        
        public:
            Fixed();
            Fixed(const Fixed& fixed); // copy constructor
            ~Fixed();
            Fixed& operator=(Fixed& other);
            // copy assigment operator overload

            int getRawBits(void);
            void setRawBits(int const raw);
};

#endif