#include <iostream>
#include <string>

using namespace std;

template <typename T>
void findSecondLargest(T anAry[], int numElm, T &secondLargest, int &loc)
{
    T greatestValue = anAry[1];
    T leastValue = anAry[1];

    for (int i = 0; i < numElm; ++i){
        if (greatestValue < anAry[i])
            greatestValue = anAry[i];
        else if ( leastValue > anAry[i])
            leastValue = anAry[i];
    }

    bool keep = false;
    if( greatestValue != leastValue){
        for(int i = 0; i < numElm; ++i){
            if(anAry[i] == greatestValue)
                continue;
            else{
                for(int j = 0; j < numElm; ++j){
                    if(anAry[j] == greatestValue)
                       continue;
                    else if( anAry[i] >= anAry[j] ){
                        keep = true;
                    }
                    else if( anAry[i] < anAry[j] ) {
                        keep = false;
                        break;
                    }
                }
            }

            if( keep ){
                secondLargest = anAry[i];
                loc = i;
            }
        }
    }
    else{
        loc = -1;
    }
}


int main()
{
    int testCases;
    string dataType;
    int numElm;
    int loc ;

    cin >> testCases;

    for(int counter = 0; counter < testCases; ++counter){
        loc = 0;
        cin >> dataType;
        if (dataType == "int"){
            cin >> numElm;
            int anAry[numElm];
            int secondLargest;
            for(int i = 0; i < numElm; ++i){
                cin >> anAry[i];
            }
            findSecondLargest( anAry, numElm, secondLargest, loc);
            if( loc != -1 )
                cout << secondLargest << " " << loc << endl;
            else{
                cout << "# " << loc << endl;
            }
        }
        else if( dataType == "double" ) {
            cin >> numElm;
            double anAry[numElm];
            double secondLargest = 0;
            for(int i = 0; i < numElm; ++i){
                cin >> anAry[i];
            }
            findSecondLargest( anAry, numElm, secondLargest, loc);
            if( loc != -1 )
                cout << secondLargest << " " << loc << endl;
            else{
                cout << "# " << loc << endl;
            }
        }
        else if( dataType == "string") {
            cin >> numElm;
            string anAry[numElm];
            string secondLargest;
            for(int i = 0; i < numElm; ++i){
                cin >> anAry[i];
            }
            findSecondLargest( anAry, numElm, secondLargest, loc);
            if( loc != -1 )
                cout << secondLargest << " " << loc << endl;
            else{
                cout << "# " << loc << endl;
            }
        }
        else return 1;
    }
    return 0;
}
