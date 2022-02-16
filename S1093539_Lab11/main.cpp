#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

void createRecord(ofstream&, const char*, string, string, double);
void removeDuplicateRecords(fstream&, const string);
void displayFile();

time_t currentTime;

int main()
{
    ofstream outClient;
    fstream fptr;
    string firstN;
    string lastN;
    double actBal = 0;
    const char *Clients = "clientFile.txt";
    const string fileN = "clientFile.txt";



    ifstream inclientFile("clientFile.txt", ios::in);

    if( !inclientFile ){
        cerr << "Creating a new file: " << endl;
    }
    else{
        cout << "Existing file contents: " << endl;
        displayFile();
    }
    outClient.open("clientFile.txt", ios::app);
    cout << "Enter first name, Last name and Balance: " << endl;
    createRecord( outClient, Clients, firstN, lastN, actBal );
    outClient.close();

    removeDuplicateRecords(fptr, fileN);
    displayFile();

    return 0;
}


void createRecord(ofstream &outClient, const char *Clients, string firstN, string lastN, double actBal)
{
    while (cin >> firstN >> lastN >> actBal ){
        outClient << firstN << " " << lastN << " " << actBal << " " << time(&currentTime) << endl;
    }
}

void displayFile()
{
    string str1;
    string str2;
    string fileN = "clientFile.txt";
    ifstream fptr;
    fptr.open(fileN);
    double balance;
    int numAct = 0;
    time_t transTime;

    if ( !fptr) {
        cerr << "File could not be opened" << endl;
        exit( 1 );
    } // end if

    while(fptr >> str1 >> str2 >> balance >> transTime) {
        cout << setw(15) << str1 << ' ' << setw(15) << str2 << ' '
        << setw(7) << balance << " " << ctime(&transTime);
        numAct++;
    }
    cout << "Number of records in the file " << fileN << ": " << numAct << endl;
}


void removeDuplicateRecords(fstream &fptr, const string fileN)
{
    fptr.open(fileN);

    if ( !fptr) {
        cerr << "File could not be opened" << endl;
        exit( 1 );
    }


    struct ClientInformation
    {
        string str1;
        string str2;
        double balance;
        time_t transTime;
    };

    ClientInformation client[1000];
    int NumberData = 0;

    for( int i = 0; i < 1000; ++i){
        fptr >> client[i].str1 >> client[i].str2 >> client[i].balance >> client[i].transTime;
        NumberData++;
    }
    fptr.close();


    fptr.open(fileN, ios::out);
    fptr.close();

    fptr.open(fileN, ios::app);
    bool keep = false;
    for(int i = 0; i < NumberData; ++i){
        for(int j = i+1; j < NumberData; ++j){
            if((client[i].str1 != client[j].str1) && (client[i].str2 != client[j].str2))
                keep = true;
            else{
                keep = false;
                break;
            }
        }
        if( keep == true){
            fptr << client[i].str1 << " " << client[i].str2 << " " << client[i].balance << " " << client[i].transTime << endl;
        }
    }
    fptr.close();
}
