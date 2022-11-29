#include <iostream>
#include <ostream>
#include <cassert>
#include <string>

class tests;

namespace diagram{
    class timing_diagram{
        private:
            int durability = 0;
            int msize = 0;
            int nsize = 0;
            unsigned char *signal;
            enum {
                NON = 0,  //x
                ZERO = 1, //0
                ONE = 2   //1
            };
        public:
            timing_diagram(int asize = 7);
            ~timing_diagram();
            timing_diagram(const timing_diagram & copied_diagram);
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
            timing_diagram operator/(unsigned char user_choice);
            friend std::ostream & operator<<(std::ostream &os, timing_diagram &diagr);  
            void set_size(int resize);
            timing_diagram operator=(timing_diagram c_dia);
            friend tests;
    };
}
