#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int number;
    int numbercases;


    cout << " Please enter the number of cases you want to try ";
    cin >> numbercases;
    for(int counter = 1; counter <= numbercases; counter++){
        int power = 0;
        int nextpowerof2 = 0;

        cout << " Please enter a integer greater or equal to 0 and lesser or equal than 1000: ";
        cin >> number;
        while (number != -1){
            if (0 <= number && number <= 1000){
                while(number >= nextpowerof2){
                    power ++;
                    nextpowerof2 = pow(2, power);
                }
            cout << nextpowerof2 << endl;
            number = -1;
            }
            else{
                cout << " Please enter a integer greater or equal to 0 and lesser or equal than 1000: ";
                cin >> number;

            }
        }
    }
    return 0;
}
