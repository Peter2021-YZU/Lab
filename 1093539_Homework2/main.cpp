#include <iostream>

using namespace std;


int main()
{
    int number;
    int iCounter = 0;
    int counter = 0;
    int numbentry = 0;


    while( cin >> number){
        if (number >= 0){
            iCounter = number-iCounter;
            if(iCounter > 0)
                counter++;
        }
        else if(number = -1)
            break;
    }

    cout << counter-1;

    return 0;
}
