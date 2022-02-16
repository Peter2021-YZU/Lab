#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

enum status {TH, TL, RT};
void generatePassWd(string &, int &);
void guess(status&, string, int);
int counter = 1;


int main()
{

	cout << "Guessing a password at most having four lowercase letters My guess is as follow: " << endl;
	status aGuess;
	string passWd = "akrd";
	int passLen = 1;
	char keepPlaying;


	guess(aGuess, passWd, passLen);

	if (aGuess == RT){
        cout << "Bravo, you guess it right!" << endl;
        if (counter <= ceil(log2(pow(26,passLen)))){
            cout << "You know the secret!" << endl;
        }
        else{
            cout << "You should be able to do better" << endl;
        }
        cout << "PLay the game again (Y or y for yes): " << " ";
    }

	while (cin >> keepPlaying){
        counter = 1;
        if (keepPlaying == 'y' || keepPlaying == 'Y'){

            guess(aGuess, passWd, passLen);

            if (aGuess == RT){
                cout << "Bravo, you guess it right!" << endl;
                if (counter <= ceil(log2(pow(26,passLen)))){
                    cout << "You know the secret!" << endl;
                }
                else{
                    cout << "You should be able to do better" << endl;
                }
                cout << "Play the game again (Y or y for yes): " << " ";
            }
        }
        else{
            break;
        }
	}
}


void guess(status &aGuess, string passWd, int passLen){

    generatePassWd(passWd, passLen);
    passWd.erase(passLen,4);
    cout << passWd << endl;
    string guessing;
    cout << "1-st guess = ";
	while(cin >> guessing){

        if(guessing == passWd){
            aGuess = RT;
            break;
        }
        else if (guessing < passWd){
            aGuess = TL;
            cout << "Too low. try again: " << endl;
        }
        else if (guessing > passWd){
            aGuess = TH;
            cout << "too high. try again: " << endl;
        }
        counter++;
        if (counter == 2)
            cout << counter << "-nd guess = ";
        else if (counter == 3)
            cout << "3-rd guess = ";
        else{
            cout << counter << "-th = ";
        }
	}
}




void generatePassWd(string &passWd, int &passLen){
	srand(time(0));
	passLen = rand()%4+1;
	for (int i=0; i<passLen; i++)
		passWd[i] = 'a' + rand()% 26;

}
