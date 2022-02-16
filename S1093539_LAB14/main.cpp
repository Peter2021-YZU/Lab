#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void displayAccount(vector <int>&, vector <string>&, vector <string>&, vector <double>&, vector <string>&, vector <string>&, vector <string>&, vector <string>&, vector <bool>&);

int main(int argc, char**argv)
{
    ifstream infile;
    vector <int> accNum;
    vector <string> fName;
    vector <string> lName;
    vector <double> actBal;
    vector <string> acTV;
    vector <string> dateV;
    vector <string> timeV;
    vector <string> validV;
    int numData = 0;
    int Number;
    string FirstN;
    string LastN;
    double Balance;
    string Type;
    string date;
    string time;
    string Valid;
    vector <bool> kept(0x80000000, true);
//    bool keeping;

    if( argc < 3 ){
        cout << "Error" << endl;
        exit(4);
    }
    //cout << argv[3] << endl;
    infile.open(argv[2],ios::in);
    if( !infile ){
        cerr << "No such file in directory! " << endl;
        exit(3);
    }
    while( infile >> Number >> FirstN >> LastN >> Balance >> Type >> date >> time >> Valid ){
        accNum.push_back(Number);
        fName.push_back(FirstN);
        lName.push_back(LastN);
        actBal.push_back(Balance);
        acTV.push_back(Type);
        dateV.push_back(date);
        timeV.push_back(time);
        validV.push_back(Valid);
        numData++;


    }
    infile.close();


    infile.open(argv[3],ios::in);
    if( !infile ){
        cerr << "No such file in directory! " << argv[1] << endl;
        exit(2);
    }
    while( infile >> Number >> FirstN >> LastN >> Balance >> Type >> date >> time >> Valid ){
        accNum.push_back(Number);
        fName.push_back(FirstN);
        lName.push_back(LastN);
        actBal.push_back(Balance);
        acTV.push_back(Type);
        dateV.push_back(date);
        timeV.push_back(time);
        validV.push_back(Valid);
        numData++;

    }
    infile.close();

    for( int i = 0; i < numData; ++i){
        for( int j = i+1; j < numData; ++j){
            if(accNum[i] > accNum[j]){
                swap(accNum[i], accNum[j]);
                swap(fName[i], fName[j]);
                swap(lName[i], lName[j]);
                swap(actBal[i], actBal[j]);
                swap(acTV[i], acTV[j]);
                swap(dateV[i], dateV[j]);
                swap(timeV[i], timeV[j]);
                swap(validV[i], validV[j]);
            }
        }
    }



    ofstream outfile;
    outfile.open( "mergedAccount.txt", ios::out );
    if( !outfile ){
        cerr << "Error, no such file in directorie! " << endl;
        exit(1);
    }
    for( int i = 0; i < numData; ++i ){
        for( int j = i+1; j < numData; ++j){
            if( accNum[i] == accNum[j] ){
                if( fName[i] == fName[j] && lName[i] == lName[j] && acTV[i] == acTV[j] && (validV[i] == "true" && validV[i] == validV[j]) ){
                    actBal[i] += actBal[j];
                    if( dateV[i] < dateV[j] ){
                        dateV[i] = dateV[j];
                    }
                    if( timeV[i] < timeV[j] ){
                        timeV[i] = timeV[j];
                    }


                    kept[i] = true;
                    kept[j] = false;
                    break;
                }
                else{
                    cout << "Inconsistent information founded for account number: " << accNum[i] << endl;
                    kept[i] = true;
                    kept[j] = true;
                    break;
                }
            }
        }
        if( kept[i] == true )
            outfile << accNum[i] << " " << fName[i] << " " << lName[i] << " " << actBal[i] << " " << acTV[i] << " " << dateV[i] << " " << timeV[i] << " " << validV[i] << "\n";

    }
    outfile.close();


    displayAccount(accNum, fName, lName, actBal, dateV, timeV, validV, acTV, kept);
}



void displayAccount(vector <int> &accNum, vector <string> &fName, vector <string> &lName, vector <double> &actBal, vector <string>&dateV, vector <string> &timeV, vector <string> &validV, vector <string> &acTV, vector <bool> &kept) // You must use the above vectors
// to store the sorted accounts. kept is a bool vector which indicates whether an account is merged and not included in the merged file.
{
    ifstream inFile("mergedAccount.txt", ios::in);
    if(!inFile){
        cout << "Error: File does not exit. " << endl;
        exit(1);
    }
    else inFile.close();

    int numActualAct=0;
    int SizeofAccNum = accNum.size();
    for(int i=0; i<SizeofAccNum; i++){
        if(kept[i]==true){
            cout<<setw(8) << setfill('0') <<accNum[i]<< setfill(' ')<<setw(10)<<fName[i]<<setw(10)<<lName[i]<<" "<<setw(8)<<actBal[i]<<" "<<setw(10) << acTV[i]<<" "<<dateV[i]<<" " <<timeV[i]<<" "<<setw(8)<<validV[i]<<endl;
            numActualAct++;
        }
    }
    cout << "Number of accounts: " << numActualAct << endl;
}
