#include <iostream>

using namespace std;

void change(long long int );

int main()
{
    long long int number;

    cout << " Enter an integer that is greater or equal than 0 and lesser or equal than 999999999999999: ";

    cin >> number;
    while(number){
        if ( number < 0 || number > 999999999999999 ){
            cout << " Please Enter an integer that is greater or equal than 0 and lesser or equal than 999999999999999: ";
            cin >> number;
        }
        else if (number == 0){
                cout << 0 << endl;
                cout << " Enter an integer that is greater or equal than 0 and lesser or equal than 999999999999999: ";
                cin >> number;
        }
        else{
                change(number);
                cout << "\n" << " Enter an integer that is greater or equal than 0 and lesser or equal than 999999999999999: ";
                cin >> number;
        }
    }

    return 0;
}

void change(long long int number)
{
    if ( number >= 10000000){
        change(number/10000000);
        cout << " kuti ";
        number = number % 10000000;
    }
    if ( number >= 100000){
        change(number/100000);
        cout << " lakh ";
        number = number % 100000;

    }
    if ( number >= 1000 ){
        change(number/1000);
        cout << " hajar ";
        number = number % 1000;
    }
    if ( number >= 100){
        change(number/100);
        cout << " shata ";
        number = number % 100;
    }
    if ( number > 0 ){
        cout << number;
    }
}
