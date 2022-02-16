#include <iostream>
#include <iomanip>
#include <string>  //local variable and global variable

using namespace std;

bool validity(string);
void convert(string);
//bool valid; //GLOBAL variable has a wide scope


int main()
{
//    string number;
//    cout << " enter a string: ";
//    while (getline(cin, number)){
//        validity(number);
//
//        if (valid){
//            int strLen = number.length();
//            if (strLen = 1)
//                break;
//            else{
//                convert(number);
//            }
//        }
//        else{
//            cout << " enter a number: ";
//            cin >> number;
//        }
//    }
    string str;
    getline(cin, str);
    cout << validity(str) ? "number string" : "non number string"; // if (validity(str)) cout << "number string " else cout << "nonnumber string"
}

void convert(string number)
{
    int flag;
    int temp;
    int strLen = number.length();
    for(int i = 0; i < strLen; ++i){
        flag = 0;
        for (int j = 0; j < (strLen - i); ++j){
            if (number[j] < number[j+1]){
                temp = number[j];
                number[j] = number[j+1];
                number[j+1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        break;
    }
    cout << number << endl;
    cout << " Enter number: ";
    cin >> number;
}





bool validity(string number)
{
    bool valid = true; //local variable
    int strLen = number.length();
    for (int k = 0; k<strLen; ++k){
        if (number[k] < 48 || number[k] > 57){ // <---------- Problem
            valid = false;
            cout << "Invalid, Please enter another string: ";
           // cin >> number;
            return valid;
        }
    }
    return valid;
}
