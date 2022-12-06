#include <iostream>
#include <cassert>
#include <string>
#include "class.hpp"

namespace diagram {

timing_diagram::timing_diagram(int asize){    //contruct
    msize = asize;
    signal = new unsigned char[asize];
    for(int i = 0; i < asize; i++){
        signal[i] = '1';
        durability = durability + ONE;
        nsize = nsize + 1;
        }
}

timing_diagram::~timing_diagram(){         //destruct
    msize = 0;
    nsize = 0;
    durability = 0;
    delete []signal;
}

timing_diagram::timing_diagram(const timing_diagram & copied_diagram){   //copy construct
    durability = copied_diagram.durability;
    msize = copied_diagram.msize;
    nsize = copied_diagram.nsize;
    signal = new unsigned char[msize];
    for(int i = 0; i < msize; i++){
        signal[i] = copied_diagram.signal[i];
    }
}

timing_diagram::timing_diagram(timing_diagram & moved_diagram){   //moving contruct
    durability = moved_diagram.durability;
    msize = moved_diagram.msize;
    nsize = moved_diagram.msize;
    signal = moved_diagram.signal;
    moved_diagram.signal = nullptr;
}

timing_diagram timing_diagram::operator=(timing_diagram c_dia){        //copy operator
    timing_diagram a_dia;
    a_dia.durability = c_dia.durability;
    a_dia.msize = c_dia.msize;
    a_dia.nsize = c_dia.nsize;
    a_dia.signal = new unsigned char[msize];
    for(int i = 0; i < msize; i++){
        a_dia.signal[i] = c_dia.signal[i];
    }
    return a_dia;
}

void timing_diagram::set_size(int resize){    //resize signal
    delete []signal;
    nsize = 0;
    msize = resize;
    durability = 0;
    signal = new unsigned char[resize];
    memset(signal, '-', msize);
}

int timing_diagram::set_durability(unsigned char user_choice){
    for(int i = 0; i < msize; i++){
        signal[i] = user_choice;
        switch(user_choice){
            case '0':
                durability = durability + ZERO;
                break;
            case '1':
                durability = durability + ONE;
                break;
            case 'x':
                durability = durability + NON;
                break;
            default:
                break;
            }
        nsize = nsize + 1;
        }
    return 0;
}

int timing_diagram::set_ascii(unsigned char user_input){ 
    if(nsize == msize){
        unsigned char *signal2;
        signal2 = new unsigned char[msize + 1];
        for(int i = 0; i < msize; i++){
            signal2[i] = signal[i];
        }
        msize = msize + 1;
        delete []signal;
        signal = signal2;
    }
    signal[nsize] = user_input;
    nsize = nsize + 1;
    switch(user_input){
        case '0':
            durability = durability + ZERO;
            break;
        case '1':
            durability = durability + ONE;
            break;
        case 'x':
            durability = durability + NON;
            break;
        default:
            break;
        }
    return 0;
}

int timing_diagram::set_normal(unsigned char user_choice){
     if(nsize == msize){
        unsigned char *signal2;
        signal2 = new unsigned char[msize + 1];
        for(int i = 0; i < msize; i++){
            signal2[i] = signal[i];
        }
        msize = msize + 1;
        delete []signal;
        signal = signal2;
    }
    signal[nsize] = user_choice;
    nsize = nsize + 1;
    switch(user_choice){
        case '0':
            durability = durability + ZERO;
            break;
        case '1':
            durability = durability + ONE;
            break;
        case 'x':
            durability = durability + NON;
            break;
        default:
            break;
    }
    return 0;
}

void timing_diagram::print(){
    std::cout << durability << std::endl;
    unsigned char t;
    unsigned char del_time;
    for (int i = 0; i < msize; i++){
        std::cout << signal[i] << " ";
        del_time = signal[i];
        signal[i] = t;
        switch(del_time){
            case '0':
                durability = durability - ZERO;
                break;
            case '1':
                durability = durability - ONE;
                break;
            case 'x':
                durability = durability - NON;
                break;
            default:
                break;
        }
    }
    memset(signal, '-', msize);
    std::cout << std::endl;
    std::cout << nsize << std::endl;
    nsize = 0;
}

int timing_diagram::copy(int number){
    int comparison = number * nsize;
    while(comparison < msize){
        unsigned char *signal2;
        signal2 = new unsigned char[msize + 1];
        for(int i = 0; i < msize; i++){
            signal2[i] = signal[i];
        }
        msize = msize + 1;
        delete []signal;
        signal = signal2;
    }  
    int i = 0;
    while(nsize != comparison){
        signal[nsize] = signal[i];
        i = i + 1;
        nsize = nsize + 1;
    }
    return 0;
}
    
int timing_diagram::move_right(int number){
    if(durability - number > 0){
        while(number >= 0){
            int i = 0;
            unsigned char choice = signal[i];
            int del;
            switch(choice){
                case '0':
                    del = ZERO;
                    break;
                case '1':
                    del = ONE;
                    break;
                case 'x':
                    del = NON;
                    break;
                default:
                    del = NON;
                    break;
            }
            number = number - del;
            unsigned char tmp;
            tmp = signal[msize - 1];
            for (int i = msize - 1; i >= 0; i--){
                signal[i] = signal[i - 1];
            }
            signal[0] = tmp;
        }
        return 0;
    }
    else return 1;
}

int timing_diagram::move_left(int number){
    if(durability - number > 0){
        while(number >= 0){
            int i = 0;
            unsigned char choice = signal[i];
            int del;
            switch(choice){
                case '0':
                    del = ZERO;
                    break;
                case '1':
                    del = ONE;
                    break;
                case 'x':
                    del = NON;
                    break;
                default:
                    del = NON;
                    break;
            }
            number = number - del;
            unsigned char tmp;
            tmp = signal[0];
            for (int i = 0; i <= msize; i++){
                signal[i] = signal[i + 1];
            }
            signal[msize - 1] = tmp;
        }
        return 0;
    }
    else return 1;
}

timing_diagram timing_diagram::operator+(int number){
    timing_diagram our_dia;
    if(durability - number > 0){
        while(number >= 0){
            int i = 0;
            unsigned char choice = signal[i];
            int del;
            switch(choice){
                case '0':
                    del = ZERO;
                    break;
                case '1':
                    del = ONE;
                    break;
                case 'x':
                    del = NON;
                    break;
                default:
                    del = NON;
                    break;
            }
            number = number - del;
            unsigned char tmp;
            tmp = signal[msize - 1];
            for (int i = msize - 1; i >= 0; i--){
                signal[i] = signal[i - 1];
            }
            signal[0] = tmp;
        }
    }
    return our_dia;
}

timing_diagram timing_diagram::operator-(int number){
    timing_diagram our_dia;
    if(durability - number > 0){
        while(number >= 0){
            int i = 0;
            unsigned char choice = signal[i];
            int del;
            switch(choice){
                case '0':
                    del = ZERO;
                    break;
                case '1':
                    del = ONE;
                    break;
                case 'x':
                    del = NON;
                    break;
                default:
                    del = NON;
                    break;
            }
            number = number - del;
            unsigned char tmp;
            tmp = signal[0];
            for (int i = 0; i <= msize; i++){
                signal[i] = signal[i + 1];
            }
            signal[msize - 1] = tmp;
        }
    }
    return our_dia;
}

timing_diagram timing_diagram::operator*(int number){ 
    timing_diagram our_dia;
    int comparison = number * nsize;
    while(comparison < msize){
        unsigned char *signal2;
        signal2 = new unsigned char[msize + 1];
        for(int i = 0; i < msize; i++){
            signal2[i] = signal[i];
        }
        msize = msize + 1;
        delete []signal;
        signal = signal2;
    }
    int i = 0;
    while(nsize != comparison){
        signal[nsize] = signal[i];
        i = i + 1;
        nsize = nsize + 1;
    }
    return our_dia;
}

timing_diagram timing_diagram::operator/(unsigned char user_choice){
    timing_diagram our_dia;
    for(nsize; nsize < msize; nsize++){
        signal[nsize] = user_choice;
        switch(user_choice){
             case '0':
                durability = durability + ZERO;
                break;
            case '1':
                durability = durability + ONE;
                break;
            case 'x':
                durability = durability + NON;
                break;
            default:
                break;
        }
    }
    return our_dia;
}
    
std::ostream & operator<<(std::ostream &os, timing_diagram &diagr){
    os << diagr.durability << std::endl;
    unsigned char t;
    unsigned char del_time;
    for (int i = 0; i < diagr.msize; i++){
        std::cout << diagr.signal[i] << " ";
        del_time = diagr.signal[i];
        diagr.signal[i] = t;
        switch(del_time){
            case '0':
                diagr.durability = diagr.durability - diagr.ZERO;
                break;
            case '1':
                diagr.durability = diagr.durability - diagr.ONE;
                break;
            case 'x':
                diagr.durability = diagr.durability - diagr.NON;
                break;
            default:
                break;
        }
    }
    std::memset(diagr.signal, '-', diagr.msize);
    std::cout << std::endl;
    std::cout << diagr.nsize << std::endl;
    diagr.nsize = 0;
    return os;
    }
}

