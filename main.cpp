#include <iostream>
#include "dialog.hpp"
#include "class.hpp"

using namespace std;

int main(){
    cout << "Hi!" << endl;
    diagram::timing_diagram dia;
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
                dia / (user_2);
                break;
            case 3:
                char user_3;
                cout << "Enter your ASCII:" << endl;
                cin >> user_3;
                dia.set_ascii(user_3);
                break;
            case 4:
                cout << "Your signal is:" << endl;
                cout << dia;
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
                dia * (number);
                break;
            case 7:
                int timel;
                cout << "Set time:" << endl;
                cin >> timel;
                dia + (timel);
                break;
            case 8:
                int timer;
                cout << "Set time:" << endl;
                cin >> timer;
                dia - (timer);
                break;
            case 9:
                int new_size;
                cout << "Set new size:" << endl;
                cin >> new_size;
                dia.set_size(new_size);
                break;
            default:
                break;
        }
    }while(flag != 1);
    return 0;
}
