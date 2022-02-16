#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int rollDice();
string crapsFunc();
enum Status {CONTINUE, WON, LOST};


int main()
{
    int crapsWon = 0;
    int numberCraps;
    char keepPlaying;
    int counter = 0;

    double winProbability;
    double bestProbability = 0;
    double probability;


    cout << "[IN] Enter the number of Craps games to be played: ";
    cin >> numberCraps;
    while(counter < numberCraps){
        if(crapsFunc() == "WON"){
            crapsWon++;
        }
        probability = crapsWon;
        winProbability = probability/100000;
        counter++;

        if(winProbability > bestProbability)
            bestProbability = winProbability;
    }
    cout << "Number of Craps games won by the player = " << crapsWon << "   ";
    cout << "Win probability = " << winProbability << endl;


    cout << "[IN] Continue to play? (Y or y for yes): ";
    while(cin >> keepPlaying){
        if (keepPlaying == 'y' || keepPlaying == 'Y'){
            crapsWon = 0;
            counter = 0;
            srand( time(0));
            while(counter < numberCraps){
                if(crapsFunc() == "WON"){
                    crapsWon++;
                }
                probability = crapsWon;
                winProbability = probability/100000;
                counter++;

                if(winProbability > bestProbability)
                    bestProbability = winProbability;
            }
            cout << "Number of Craps games won by the player = " << crapsWon << "   ";
            cout << "Win probability = " << winProbability << endl;
            cout << "[IN] Continue to play? (Y or y for yes): ";
        }
        else{
            cout << "The best win Probability = " << bestProbability << endl;
            break;
        }
    }
}


string crapsFunc()
{

    string gameResult = "LOST";
	Status gameStatus;
	int sumOfDice = rollDice();
	int myPoint;

	switch ( sumOfDice )
	{
		case 7:
		case 11:
        case 4:
        case 5:
        case 9:
			gameStatus = WON;
			break;
		case 2:
		case 12:
		    gameStatus = LOST;
		    break;
        default:
			gameStatus = CONTINUE;
			myPoint = sumOfDice;
			break;
	}


	while (gameStatus == CONTINUE)
	{
		sumOfDice = rollDice();
		if ( sumOfDice == myPoint )
			gameStatus = WON;
		else{
			if ( sumOfDice == 7 )
				gameStatus = LOST;
		}
	}

	if (gameStatus ==WON){
        gameResult = "WON";
	}
	return gameResult;
}


int rollDice()
{
	int die1 = 1 + rand() % 6;
	int die2  = 1 + rand() % 6;

	int sum = die1 + die2;
	return sum;
}
