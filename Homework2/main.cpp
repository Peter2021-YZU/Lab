#include <iostream>

using namespace std;


int main()
{

    int number;
    int counter = 0;
    int arr[11] = {};
    int index;

    for (index = 0; index < 11; ++index){
        cin >> number;
        arr[index]=number;
        if(index > 0){
            if (arr[index] > arr[index-1])
                counter++;
            }


        if (number == -1){
            if ( index < 2){
                cout << "You should enter from two to ten numbers!" << endl;
            }
            else{
                cout << counter << endl;
            }
            break;
        }
        else if (number < 0){
            cout << "all numbers should be positive";
            break;
        }
    }

    return 0;
}
