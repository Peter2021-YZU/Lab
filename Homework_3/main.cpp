#include <iostream>
#include <math.h>

using namespace std;

void inputArray(int[], int);
bool verifySum (int[], int);

int numbInput;
//int input;
int arr[10] = {};



int main()
{
    cin >> numbInput;
    if (numbInput >= 2 && numbInput <= 10){
        inputArray(arr, numbInput);
        }
        bool valid;
        for (int i = 0; i < numbInput; ++i){
            if (arr[i] >= 0)
                valid = true;
            else{
                cout << "Number should be positive";
                valid = false;
                break;
            }
        }

        if(valid){
            if (verifySum(arr, numbInput))
                cout << "yes";
            else{
                cout << "no";
            }
        }
    return 0;
}

void inputArray(int arr[], int numbInput)
{
    for (int i = 0; i < numbInput; ++i){
        cin >> arr[i];
    }
}




bool verifySum(int arr[], int numbInput)
{
    bool verifySum = false;
    int index = 0;
    int sum = 0;
    int numberCases = pow(2,numbInput)-1;

    for (int i = 1; i <= numberCases; i++){
        int temp = i;
        while (temp > 0){
            if (temp & 1){
                sum += arr[index];
            }
            temp = (temp >> 1);
            index++;
        }
        if (sum == 1000){
            verifySum = true;
            break;
        }
        sum = 0;
        index = 0;
    }
    return verifySum;
}
