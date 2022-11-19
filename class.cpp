#include "class.hpp"

namespace diagram{
    
timing_diagram::timing_diagram(){
    unsigned char classiq = '1';
    memset(signal, '-', 32);
    for(int i = 0; i < 16; i++){
        signal[i] = classiq;
        nsize = nsize + 1;
        durability = durability + ONE;
    }
}

timing_diagram::~timing_diagram(){
    unsigned char free_element;
    unsigned char del_element;
    for(int i = 0; i <= nsize; i++){
        del_element = signal[i];
        signal[i] = free_element;
        nsize = nsize - 1;
        switch(del_element){
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
}

int timing_diagram::set_durability(unsigned char user_choice){
    if (nsize >= msize)
        return 1;
    else{
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
        return 0;
    }
}

int timing_diagram::set_ascii(unsigned char user_input){
    if(nsize >= msize)
        return 1;
    else{
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
}

int timing_diagram::set_normal(unsigned char user_choice){
    if(nsize >= msize){
        return 1;
    }
    else{
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
    memset(signal, '-', 32);
    std::cout << std::endl;
    std::cout << nsize << std::endl;
    nsize = 0;
}

int timing_diagram::copy(int number){
    int comparison = number * nsize;
    if(comparison < msize){
        int i = 0;
        while(nsize != comparison){
            signal[nsize] = signal[i];
            i = i + 1;
            nsize = nsize + 1;
        }
        return 0;
    }
    else return 1;
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
                signal[i] = signal[i-1];
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
                signal[i] = signal[i-1];
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
    if(comparison < msize){
        int i = 0;
        while(nsize != comparison){
            signal[nsize] = signal[i];
            i = i + 1;
            nsize = nsize + 1;
        }
    }
    return our_dia;
}

timing_diagram timing_diagram::operator=(unsigned char user_choice){
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
    std::memset(diagr.signal, '-', 32);
    std::cout << std::endl;
    std::cout << diagr.nsize << std::endl;
    diagr.nsize = 0;
    return os;
}

}
