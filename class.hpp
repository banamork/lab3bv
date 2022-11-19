#include <iostream>
#include <ostream>


namespace diagram{
    class timing_diagram{
        private:
            int durability = 0;
            int msize = 32;
            int nsize = 0;
            unsigned char signal[32];
            enum {
                NON = 0,
                ZERO = 1,
                ONE = 2
            };
        public:
            timing_diagram();
            ~timing_diagram();
            int set_durability(unsigned char user_choice);
            int set_ascii(unsigned char user_input);
            int set_normal(unsigned char user_choice);
            void print();
            int copy(int number);
            int move_right(int number);
            int move_left(int number);
            timing_diagram operator+(int number);
            timing_diagram operator-(int number);
            timing_diagram operator*(int number);
            timing_diagram operator=(unsigned char user_choice);
            friend std::ostream & operator<<(std::ostream &os, timing_diagram &diagr); 
   };
}    
