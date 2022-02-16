
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int tests = 11;
const int students = 201;
void readGrades( ifstream&, double [][ tests ], int&, int& );
void minimum( double [][ tests ], int&, int& );
void maximum( double [][ tests ], int&, int& );
void average( double [][tests], int&, int& );
void outputGrades( double [][ tests ], int&, int& );
void outputBarChart( double [][ tests ], int&, int& );
void outputBarVerChart( double [][tests], int&, int& );

int main()
{
    string FileN;
    cin >> FileN;
    ifstream infile(FileN, ios::in);
    int numStudents;
    int numTests;
    double studentGrades[students][tests] = {0.00};

    readGrades(infile, studentGrades, numStudents, numTests);

    average(studentGrades, numStudents, numTests);

    outputGrades(studentGrades, numStudents, numTests);
    cout << "\n";

    outputBarChart(studentGrades, numStudents, numTests);
    cout << "\n";
    outputBarVerChart( studentGrades, numStudents, numTests );
    return 0;
}


void readGrades(ifstream &infile, double studentGrades[][tests], int &numStudents, int &numTests)
{

    if (!infile){
        cerr << "File does not exist" << endl;
    }
    else{
        infile >> numStudents;
        infile >> numTests;
        for( int i = 0; i < numStudents; ++i){
            for (int j = 0; j < numTests; ++j){
                infile >> studentGrades[i][j];
            }
        }
    }
}

void minimum( double studentGrades[][tests], int &numStudents, int &numTests )
{
    cout << "minimum" << setw(4) << " ";
    for (int test = 0; test < numTests; ++test){
        int lowGrade = 100;
        for (int student = 0; student < numStudents; ++student){
            if( studentGrades[student][test] <= lowGrade ){
                lowGrade = studentGrades[student][test];
            }
        }
        cout << setw(10) << lowGrade;
    }
    double lowGrade = 100;
    for (int student = 0; student < numStudents; ++student){
        if( studentGrades[student][10] <= lowGrade ){
            lowGrade = studentGrades[student][10];
        }
    }
    cout << setw(10) << lowGrade;
}

void maximum( double studentGrades[][tests], int &numStudents, int &numTests )
{
    cout << "maximum" << setw(4) << " ";
    for (int test = 0; test < numTests; ++test){
        int highGrade = 100;
        for (int student = 0; student < numStudents; ++student){
            if( studentGrades[student][test] >= highGrade ){
                highGrade = studentGrades[student][test];
            }
        }
        cout << setw(10) << highGrade;
    }
    double highGrade = 100;
    for (int student = 0; student < numStudents; ++student){
        if( studentGrades[student][10] >= highGrade ){
            highGrade = studentGrades[student][10];
        }
    }
    cout << setw(10) << highGrade;
}

void average( double studentGrades[][tests], int &numStudents, int &numTests )
{
    for( int i = 0; i < numStudents; ++i ){
        double avr = 0;
        for (int j = 0; j < numTests; ++j){
            double ConvGrade = studentGrades[i][j];
            avr += ( ConvGrade / numTests );
        }
        studentGrades[i][10] = avr;
    }

    for( int j = 0; j < numTests; ++j ){
        int avr;
        int sum = 0;
        for( int i = 0; i < numStudents; ++i ){
            sum = sum + studentGrades[i][j];
        }
        avr = sum / numStudents;
        studentGrades[200][j] = avr;
    }
}


void outputGrades( double studentGrades[][tests], int &numStudents, int &numTests )
{
    cout << "The actual number of students: " << numStudents << "\n";
    cout << "The actual number of tests: " << numTests << "\n";
    cout << "\nThe grades are:" << endl;;
    cout << "\n";
    cout << setw(18);
    for( int j = 1; j < numTests + 1; ++j ){
        cout << "Test" << setw(3) << j << setw(7);
    }
    cout << setw(11) << " Average\n";

    cout << setw(21);
    for( int j = 0; j < numTests + 1; ++j ){
        cout << "-------" << setw(10);
    }
    cout << "\n";

    for( int i = 1; i < numStudents + 1; ++i){
        cout << "Student" << setw(4) << i << setw(18);
        for (int j = 0; j < numTests; ++j){
            if( i == 1 ){
                cout << setw(10) << setprecision(2) << studentGrades[i-1][j];
            }
            else if( i > 1){
                cout << setw(10) << noshowpoint << setprecision(0) << studentGrades[i-1][j];
            }
        }
        cout << setw(10) << fixed <<  showpoint << setprecision(2) << studentGrades[i-1][10] << endl;
    }


    cout << setw(21);
    for( int j = 0; j < numTests + 1; ++j ){
        cout << "-------" << setw(10);
    }
    cout << "\nAverage" << setw(4) << " ";
    for (int j = 0; j < numTests ; ++j){
        cout << setw(10) << noshowpoint << setprecision(0) << studentGrades[200][j];
    }
    double sum = 0;
    for( int i = 0; i < numStudents; ++i ){
        sum = sum + studentGrades[i][10];
    }
    double avrAvreages = sum / numStudents;
    cout << setw(10) << fixed << showpoint << setprecision(2) << avrAvreages;

    cout << "\n";
    minimum( studentGrades, numStudents, numTests );
    cout << "\n";
    maximum( studentGrades, numStudents, numTests );
}




void outputBarChart( double studentGrades[][tests], int &numStudents, int &numTests )
{

    cout << endl;
    cout << "Overall grade distribution (Horizontal bar chart) :" << endl;
    cout << "---------------------------------------------------" << endl;
    const int FrequencySize = 12;
    int Frequency[FrequencySize] = {};

    for( int i = 0; i < numStudents; ++i){
        for (int j = 0; j < numTests; ++j){;
            double ConvertGrade = studentGrades[ i ][ j ];
            double division = ConvertGrade / 10;

            if( division  == 0 ){
                Frequency[0]++;
            }
            else if( division < 1 )
                Frequency[1]++;
            else if( division < 2 )
                Frequency[2]++;
            else if( division < 3 )
                Frequency[3]++;
            else if( division < 4 )
                Frequency[4]++;
            else if( division < 5 )
                Frequency[5]++;
            else if( division < 6 )
                Frequency[6]++;
            else if( division < 7 )
                Frequency[7]++;
            else if( division < 8 )
                Frequency[8]++;
            else if( division < 9 )
                Frequency[9]++;
            else if( division < 10 )
                Frequency[10]++;
            else{
                Frequency[11]++;
            }
        }
    }
    for( int counter = 0; counter < FrequencySize; counter++ ){
        if( counter == 0 ){
            cout << "    0: ";
        }
        else if( counter > 10 ){
            cout << "  100: ";
        }
        else if( counter == 1 ){
            cout << "  1-9: ";
        }
        else{
            cout << (counter-1) * 10 << "-" << ((counter-1) * 10) + 9 << ": ";
        }

        for( int stars = 0; stars < Frequency[ counter ]; stars++ ){
            cout << "*";
        }
        if( Frequency[counter] == 0 )
            cout << endl;
        else{
            cout << " " << Frequency[counter] << endl;
        }
    }
}


void outputBarVerChart( double studentGrades[][tests], int &numStudents, int &numTests )
{
    cout << "\n";
    cout << "Overall grade distribution (Vertical bar chart):" << endl;
    cout << "-------------------------------------------------" << endl;
    const int FrequencySize = 12;
    int Frequency[FrequencySize] = {};

    for( int i = 0; i < numStudents; ++i){
        for (int j = 0; j < numTests; ++j){;
            double ConvertGrade = studentGrades[ i ][ j ];
            double division = ConvertGrade / 10;

            if( division  == 0 ){
                Frequency[0]++;
            }
            else if( division < 1 )
                Frequency[1]++;
            else if( division < 2 )
                Frequency[2]++;
            else if( division < 3 )
                Frequency[3]++;
            else if( division < 4 )
                Frequency[4]++;
            else if( division < 5 )
                Frequency[5]++;
            else if( division < 6 )
                Frequency[6]++;
            else if( division < 7 )
                Frequency[7]++;
            else if( division < 8 )
                Frequency[8]++;
            else if( division < 9 )
                Frequency[9]++;
            else if( division < 10 )
                Frequency[10]++;
            else{
                Frequency[11]++;
            }
        }
    }

    cout << "  " << "0" << setw(8) << " 1-9" << setw(9) << " 10-19" << setw(8) << " 20-29" << setw(8) << " 30-39" << setw(8) << " 40-49" << setw(8) << " 50-59" << setw(8) << " 60-69" << setw(8) << " 70-79" << setw(8) << " 80-89" << setw(8) << " 90-99" << setw(9) << " 100" << endl;
    cout <<"---------------------------------------------------------------------------------------------" << endl;
    int wCounter = 0;
    int bound = numStudents * numTests;
    while( wCounter < bound ){
        cout << "  ";
        for( int counter = 0; counter < FrequencySize; counter++ ){
            if( Frequency[counter] == 0)
                cout << " " << setw(8);
            else if( wCounter < Frequency[counter]){
                cout << "*" << setw(8);
            }
            else if ( wCounter == Frequency[counter] ){
                cout << Frequency[counter] << setw(8);
            }
            else if( wCounter > Frequency[counter] ){
                cout << " " << setw(8);
            }
        }
        cout << "\n";
        wCounter++;
    }
}
