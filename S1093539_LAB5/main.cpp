#include <iostream>
#include <string>

using namespace std;

bool validity(string);
void sort(string);


string str;
int strLen;

int main()
{
    cout << " Enter a string or Enter a string that contains only one number to quit: ";
    while(getline(cin, str)){
        strLen = str.length();
        validity(str);
        if (validity(str)){
            if (strLen == 1){
                break;
            }
            else{
                sort(str);
            }

        }
        else{
            cout << " Invalid, Please enter another string that contains only positive numbers: ";
        }
    }
}

void sort(string str)
{
    int sorted;
    int temp;
    for(int i = 0; i < strLen; ++i){
        sorted = 0;
        for (int j = 0; j < (strLen - i - 1); ++j){
            if (str[j] < str[j+1]){
                temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
                sorted = 1;
            }
        }
        if (sorted == 0)
            break;
    }
    cout << str << endl;
    cout << " Enter a string or Enter a string that contains only one number to quit: ";
}





bool validity(string str)
{
    bool valid = true;
    for (int k = 0; k<strLen; ++k){
        if (str[k] < 48 || str[k] > 57){
            valid = false;
            return valid;
        }
    }
    return valid;
}
