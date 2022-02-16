#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    string word;
    string answer ="";
    string goldAnswer = "";
    int counter = 0;
    string keep = "y";
    int run = 1;
    bool verify = false;
    bool goldVerify = false;
    ifstream inputFile("Input-for-lab 15.txt", ios::in);

    if( !inputFile ){
        cerr << "No such file in directories! ";
        exit(1);
    }
    while(keep == "y" || keep == "Y" ){
        getline(inputFile, word);
        if( word == "!@#$%" ){
            counter++;
            cout << word << endl;

        }
        else{
            if( counter == 0 ){
                answer += word;
                cout << word << endl;

                for(int i = 0; i < answer.length(); ++i){
                    if( answer[i] != 32 && answer[i] != '\t' && answer[i] != '\n')
                        verify = true;
                        break;
                }
                cout << "---------" << verify << "--------" << endl;
                if( !verify ){
                    answer.clear();
                }
            }
            else if( counter == 1 ){
                goldAnswer += word;
                cout << word << endl;

                for(int i = 0; i < goldAnswer.length(); ++i){
                    if( goldAnswer[i] != ' '  && goldAnswer[i] != '\t' && goldAnswer[i] != '\n')
                        goldVerify = true;
                        break;
                }

                cout << "&&&&&&&& " << verify << " &&&&&&&&&&" << endl;
                if(!goldVerify)
                    goldAnswer.clear();
            }
            else if( counter == 2 ){
                cout << "run #" << run << ": ";
                if( goldAnswer == answer )
                    cout << "Accepted" << endl;
                else{
                    goldAnswer.erase(remove(goldAnswer.begin(), goldAnswer.end(), ' '), goldAnswer.end());
                    goldAnswer.erase(remove(goldAnswer.begin(), goldAnswer.end(), '\t'), goldAnswer.end());
                    goldAnswer.erase(remove(goldAnswer.begin(), goldAnswer.end(), '\n'), goldAnswer.end());


                    answer.erase(remove(answer.begin(), answer.end(), ' '), answer.end());
                    answer.erase(remove(answer.begin(), answer.end(), '\t'), answer.end());
                    answer.erase(remove(answer.begin(), answer.end(), '\n'), answer.end());


                    if(answer == goldAnswer){
                        cout << "Presentation Error" << endl;
                    }
                    else{
                        cout << "Wrong Answer" << endl;
                    }
                }
                answer = "";
                goldAnswer = "";
                cout << "Evaluate more program's output: ";
                keep = word;
                cout <<"-----" << keep << endl;
                run++;
                counter = 0;
            }
        }
    }

    return 0;
}
