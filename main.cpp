#include <iostream>
#include "dialog.hpp"
#include "class.hpp"

using namespace std;

int main(){
    cout << "Hi!" << endl;
    timing_diagram dia;
    int flag = 0;
    do{
        int var = menu();
        switch(var){
            case 1:
                flag = 1;
                break;
            case 2:
                unsigned char user_2;
                cout << "Enter your signal:" << endl;
                cin >> user_2;
                dia.set_durability(user_2);
                break;
            case 3:
                char user_3;
                cout << "Enter your ASCII:" << endl;
                cin >> user_3;
                dia.set_ascii(user_3);
                break;
            case 4:
                cout << "Your signal is:" << endl;
                dia.print();
                break;
            case 5:
                unsigned char user_5;
                cout << "Get me one of your signal:" << endl;
                cin >> user_5;
                dia.set_normal(user_5);
                break;
            case 6:
                int number;
                cout << "Set amount:" << endl;
                cin >> number;
                if(dia.copy(number) == 1){
                    cout << "Not size for this." << endl;
                    break;
                }
                else{
                    dia.copy(number);
                    break;
                }
            case 7:
                int timel;
                cout << "Set time:" << endl;
                cin >> timel;
                dia.move_left(timel);
                break;
            case 8:
                int timer;
                cout << "Set time:" << endl;
                cin >> timer;
                dia.move_right(timer);
                break;
            default:
                break;
        }
    }while(flag != 1);
    return 0;
}