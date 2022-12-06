#include <iostream>
#include "class.hpp"
#include <cstdint>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

class tests{
    public:
        int find_size(diagram::timing_diagram td){
            int our_size;
            our_size = sizeof(&td.signal)/sizeof(&td.signal[0]);
            return our_size;
        };
        int return_msize(diagram::timing_diagram td){
            int max_size;
            max_size = td.msize;
            return max_size;
        }
        int return_durability(diagram::timing_diagram td){
            int durab;
            durab = td.durability;
            return durab;
        }
        int true_copy(diagram::timing_diagram td){
            diagram::timing_diagram copdia;
            int durab = td.durability;
            int ms = td.msize;
            int ns = td.nsize;
            td = copdia;
            if(td.durability != durab || td.nsize != ns || td.msize != ms)
                return 1;
            else 
                return 0;
        }
};

TEST_CASE( "Timing Diagram test1!" ){
    std::cout << "Test has been started." << std::endl;
    SECTION("SIZE: BASIC SIZE AND RESIZE"){
        diagram::timing_diagram test1;
        tests num1;
        REQUIRE(7 == num1.find_size(test1));
        test1.set_size(8); 
        REQUIRE(8  == num1.find_size(test1));
        REQUIRE(8 == num1.return_msize(test1));
    }
    SECTION("SIZE AFTER COPY"){
        diagram::timing_diagram test2;
        tests num2;
        test2.copy(2);
        REQUIRE(num2.find_size(test2) == num2.return_msize(test2));    
    }
    SECTION("SIZE AFTER SET NORMAL"){
        diagram::timing_diagram test3;
        tests num3;
        int start_size = num3.return_msize(test3);
        test3.set_normal('1');
        REQUIRE((start_size + 2) == num3.return_msize(test3));
    }
    SECTION("DURABILITY AFTER SET '0' IN SET NORMAL"){
        diagram::timing_diagram test4;
        tests num4;
        int before = num4.return_durability(test4);
        test4.set_normal('0');
        REQUIRE((before + 1) == num4.return_durability(test4));
    }
    SECTION("TEST COPY CONSTRUCT"){
        diagram::timing_diagram test5;
        tests num5;
        REQUIRE(0 == num5.true_copy(test5));
    }
}

TEST_CASE( "Timing Diagram test2!" ){
    std::cout << "Test has been started." << std::endl;
    SECTION("SIZE: RESIZE"){
        diagram::timing_diagram test1;
        tests num1;
        test1.set_size(9); 
        REQUIRE(9  == num1.find_size(test1));
        REQUIRE(9 == num1.return_msize(test1));
    }
    SECTION("SIZE AFTER COPY"){
        diagram::timing_diagram test2;
        tests num2;
        test2.copy(3);
        REQUIRE(num2.find_size(test2) == num2.return_msize(test2));    
    }
    SECTION("SIZE AFTER SET NORMAL"){
        diagram::timing_diagram test3;
        tests num3;
        int start_size = num3.return_msize(test3);
        test3.set_normal('0');
        REQUIRE((start_size + 1) == num3.return_msize(test3));
    }
    SECTION("DURABILITY AFTER SET '1' IN SET NORMAL"){
        diagram::timing_diagram test4;
        tests num4;
        int before = num4.return_durability(test4);
        test4.set_normal('1');
        REQUIRE((before + 2) == num4.return_durability(test4));
    }
    SECTION("TEST COPY CONSTRUCT"){
        diagram::timing_diagram test5;
        tests num5;
        REQUIRE(0 == num5.true_copy(test5));
    }
}
