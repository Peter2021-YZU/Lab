#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;


int main()
{

    string input;
    int wordsCounter = 0;
    int inputLength;
    char firstlet;
    char lastlet;
    char samelet;
    int start_vowel = 0;
    int start_alphabet = 0;
    int start_consomn = 0;
    int start_digit = 0;
//    int Length0 = 0;
//    int Length1 = 0;
//    int Length2 = 0;
//    int Length3 = 0;
//    int Length4 = 0;
//    int Length5 = 0;
//    int Length6 = 0;
//    int Length7 = 0;
//    int Length8 = 0;
//    int Length9 = 0;
//    int Length10 = 0;
//    int Length11 = 0;
//    int Length12 = 0;
//    int Length13 = 0;
//    int Length14 = 0;
    int Length[15] = {};
    int firstLetterA = 0;
    int firstLetterB = 0;
    int firstLetterC = 0;
    int firstLetterD = 0;
    int firstLetterE = 0;
    int firstLetterF = 0;
    int firstLetterG = 0;
    int firstLetterH = 0;
    int firstLetterI = 0;
    int firstLetterJ = 0;
    int firstLetterK = 0;
    int firstLetterL = 0;
    int firstLetterM = 0;
    int firstLetterN = 0;
    int firstLetterO = 0;
    int firstLetterP = 0;
    int firstLetterQ = 0;
    int firstLetterR = 0;
    int firstLetterS = 0;
    int firstLetterT = 0;
    int firstLetterU = 0;
    int firstLetterV = 0;
    int firstLetterW = 0;
    int firstLetterX = 0;
    int firstLetterY = 0;
    int firstLetterZ = 0;
    int sameLetterA = 0;
    int sameLetterB = 0;
    int sameLetterC = 0;
    int sameLetterD = 0;
    int sameLetterE = 0;
    int sameLetterF = 0;
    int sameLetterG = 0;
    int sameLetterH = 0;
    int sameLetterI = 0;
    int sameLetterJ = 0;
    int sameLetterK = 0;
    int sameLetterL = 0;
    int sameLetterM = 0;
    int sameLetterN = 0;
    int sameLetterO = 0;
    int sameLetterP = 0;
    int sameLetterQ = 0;
    int sameLetterR = 0;
    int sameLetterS = 0;
    int sameLetterT = 0;
    int sameLetterU = 0;
    int sameLetterV = 0;
    int sameLetterW = 0;
    int sameLetterX = 0;
    int sameLetterY = 0;
    int sameLetterZ = 0;


    while( cin >> input ){
        wordsCounter++;

        firstlet = tolower(input[0]);
        inputLength = input.length();




        switch(firstlet){
            case 'a':{
                start_vowel++;
                start_alphabet++;
                firstLetterA++;
                break;
            }
            case 'b':{
                start_consomn++;
                start_alphabet++;
                firstLetterB++;
                break;
            }
            case 'c':{
                start_consomn++;
                start_alphabet++;
                firstLetterC++;
                break;
            }
            case 'd':{
                start_consomn++;
                start_alphabet++;
                firstLetterD++;
                break;
            }
            case 'e':{
                start_vowel++;
                start_alphabet++;
                firstLetterE++;
                break;
            }
            case 'f':{
                start_consomn++;
                start_alphabet++;
                firstLetterF++;
                break;
            }
            case 'g':{
                start_consomn++;
                start_alphabet++;
                firstLetterG++;
                break;
            }
            case 'h':{
                start_consomn++;
                start_alphabet++;
                firstLetterH++;
                break;
            }
            case 'i':{
                start_vowel++;
                start_alphabet++;
                firstLetterI++;
                break;
            }
            case 'j':{
                start_consomn++;
                start_alphabet++;
                firstLetterJ++;
                break;
            }
            case 'k':{
                start_consomn++;
                start_alphabet++;
                firstLetterK++;
                break;
            }
            case 'l':{
                start_consomn++;
                start_alphabet++;
                firstLetterL++;
                break;
            }
            case 'm':{
                start_consomn++;
                start_alphabet++;
                firstLetterM++;
                break;
            }
            case 'n':{
                start_consomn++;
                start_alphabet++;
                firstLetterN++;
                break;
            }
            case 'o':{
                start_vowel++;
                start_alphabet++;
                firstLetterO++;
                break;
            }
            case 'p':{
                start_consomn++;
                start_alphabet++;
                firstLetterP++;
                break;
            }
            case 'q':{
                start_consomn++;
                start_alphabet++;
                firstLetterQ++;
                break;
            }
            case 'r':{
                start_consomn++;
                start_alphabet++;
                firstLetterR++;
                break;
            }
            case 's':{
                start_consomn++;
                start_alphabet++;
                firstLetterS++;
                break;
            }
            case 't':{
                start_consomn++;
                start_alphabet++;
                firstLetterT++;
                break;
            }
            case 'u':{
                start_vowel++;
                start_alphabet++;
                firstLetterU++;
                break;
            }
            case 'v':{
                start_consomn++;
                start_alphabet++;
                firstLetterV++;
                break;
            }
            case 'w':{
                start_consomn++;
                start_alphabet++;
                firstLetterW++;
                break;
            }
            case 'x':{
                start_consomn++;
                start_alphabet++;
                firstLetterX++;
                break;
            }
            case 'y':{
                start_consomn++;
                start_alphabet++;
                firstLetterY++;
                break;
            }
            case 'z':{
                start_consomn++;
                start_alphabet++;
                firstLetterZ++;
                break;
            }
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':{
                start_digit++;
                break;
            }
            default:
                break;
        }

        if (input[inputLength-1] == '.' || input[inputLength-1] == ',' || input[inputLength-1] == ':')
            lastlet = input[inputLength-2];
        else{
            lastlet = input[inputLength-1];
        }

        if ((lastlet == firstlet) && (inputLength > 1)){
            samelet = lastlet;

            switch(samelet){
                case 'a':{
                    sameLetterA++;
                    break;
                }
                case 'b':{
                    sameLetterB++;
                    break;
                }
                case 'c':{
                    sameLetterC++;
                    break;
                }
                case 'd':{
                    sameLetterD++;
                    break;
                }
                case 'e':{
                    sameLetterE++;
                    break;
                }
                case 'f':{
                    sameLetterF++;
                    break;
                }
                case 'g':{
                    sameLetterG++;
                    break;
                }
                case 'h':{
                    sameLetterH++;
                    break;
                }
                case 'i':{
                    sameLetterI++;
                    break;
                }
                case 'j':{
                    sameLetterJ++;
                    break;
                }
                case 'k':{
                    sameLetterK++;
                    break;
                }
                case 'l':{
                    sameLetterL++;
                    break;
                }
                case 'm':{
                    sameLetterM++;
                    break;
                }
                case 'n':{
                    sameLetterN++;
                    break;
                }
                case 'o':{
                    sameLetterO++;
                    break;
                }
                case 'p':{
                    sameLetterP++;
                    break;
                }
                case 'q':{
                    sameLetterQ++;
                    break;
                }
                case 'r':{
                    sameLetterR++;
                    break;
                }
                case 's':{
                    sameLetterS++;
                    break;
                }
                case 't':{
                    sameLetterT++;
                    break;
                }
                case 'u':{
                    sameLetterU++;
                    break;
                }
                case 'v':{
                    sameLetterV++;
                    break;
                }
                case 'w':{
                    sameLetterW++;
                    break;
                }
                case 'x':{
                    sameLetterX++;
                    break;
                }
                case 'y':{
                    sameLetterY++;
                    break;
                }
                case 'z':{
                    sameLetterZ++;
                    break;
                }
            }
        }

        if (input[inputLength-1] == '.' || input[inputLength-1] == ',' || input[inputLength-1] == ':'){
            inputLength -= 1;
        }
        switch(inputLength){
            case 0:
                Length[0]++;
                break;
            case 1:
                Length[1]++;
                break;
            case 2:
                Length[2]++;
                break;
            case 3:
                Length[3]++;
                break;
            case 4:
                Length[4]++;
                break;
            case 5:
                Length[5]++;
                break;
            case 6:
                Length[6]++;
                break;
            case 7:
                Length[7]++;
                break;
            case 8:
                Length[8]++;
                break;
            case 9:
                Length[9]++;
                break;
            case 10:
                Length[10]++;
                break;
            case 11:
                Length[11]++;
                break;
            case 12:
                Length[12]++;
                break;
            case 13:
                Length[13]++;
                break;
            case 14:
                Length[14]++;
                break;
            default:
                Length[15]++;
                break;
        }
    }

    cout << "Total number of words: " << wordsCounter << endl;
    cout << "Total number of words starting by vowel: " << start_vowel << endl;
    cout << "Total number of words not starting with a vowel, but with an alphabet : " << start_consomn << endl;
    cout << "Total number of words started with an alphabet: " << start_alphabet << endl;
    cout << "Total number started with a digit: " << start_digit << endl;
    cout << "Distribution of words by word length: " << endl;
    cout << "L=0 " << Length[0] << endl;
    cout << "L=1 " << Length[1] << endl;
    cout << "L=2 " << Length[2] << endl;
    cout << "L=3 " << Length[3] << endl;
    cout << "L=4 " << Length[4] << endl;
    cout << "L=5 " << Length[5] << endl;
    cout << "L=6 " << Length[6] << endl;
    cout << "L=7 " << Length[7] << endl;
    cout << "L=8 " << Length[8] << endl;
    cout << "L=9 " << Length[9] << endl;
    cout << "L=10 " << Length[10] << endl;
    cout << "L=11 " << Length[11] << endl;
    cout << "L=12 " << Length[12] << endl;
    cout << "L=13 " << Length[13] << endl;
    cout << "L=14 " << Length[14] << endl;
    cout << "L>=15 " << Length[15] << endl;
    cout << "Distribution of words by first letter: " << endl;
    cout << "A/a: " << firstLetterA << endl;
    cout << "B/b: " << firstLetterB << endl;
    cout << "C/c: " << firstLetterC << endl;
    cout << "D/d: " << firstLetterD << endl;
    cout << "E/e: " << firstLetterE << endl;
    cout << "F/f: " << firstLetterF << endl;
    cout << "G/g: " << firstLetterG << endl;
    cout << "H/h: " << firstLetterH << endl;
    cout << "I/i: " << firstLetterI << endl;
    cout << "J/j: " << firstLetterJ << endl;
    cout << "K/k: " << firstLetterK << endl;
    cout << "L/l: " << firstLetterL << endl;
    cout << "M/m: " << firstLetterM << endl;
    cout << "N/n: " << firstLetterN << endl;
    cout << "O/o: " << firstLetterO << endl;
    cout << "P/p: " << firstLetterP << endl;
    cout << "Q/q: " << firstLetterQ << endl;
    cout << "R/r: " << firstLetterR << endl;
    cout << "S/s: " << firstLetterS << endl;
    cout << "T/t: " << firstLetterT << endl;
    cout << "U/u: " << firstLetterU << endl;
    cout << "V/v: " << firstLetterV << endl;
    cout << "W/w: " << firstLetterW << endl;
    cout << "X/x: " << firstLetterX << endl;
    cout << "Y/y: " << firstLetterY << endl;
    cout << "Z/z: " << firstLetterZ << endl;
    cout << "0~9: " << start_digit << endl;
    cout << "Other: " << wordsCounter - (start_alphabet+start_digit) << endl;
    cout << "Distribution of words first and last letters are the same: " << endl;
    cout << "A/a: " << sameLetterA << endl;
    cout << "B/b: " << sameLetterB << endl;
    cout << "C/c: " << sameLetterC << endl;
    cout << "D/d: " << sameLetterD << endl;
    cout << "E/e: " << sameLetterE << endl;
    cout << "F/f: " << sameLetterF << endl;
    cout << "G/g: " << sameLetterG << endl;
    cout << "H/h: " << sameLetterH << endl;
    cout << "I/i: " << sameLetterI << endl;
    cout << "J/j: " << sameLetterJ << endl;
    cout << "K/k: " << sameLetterK << endl;
    cout << "L/l: " << sameLetterL << endl;
    cout << "M/m: " << sameLetterM << endl;
    cout << "N/n: " << sameLetterN << endl;
    cout << "O/o: " << sameLetterO << endl;
    cout << "P/p: " << sameLetterP << endl;
    cout << "Q/q: " << sameLetterQ << endl;
    cout << "R/r: " << sameLetterR << endl;
    cout << "S/s: " << sameLetterS << endl;
    cout << "T/t: " << sameLetterT << endl;
    cout << "U/u: " << sameLetterU << endl;
    cout << "V/v: " << sameLetterV << endl;
    cout << "W/w: " << sameLetterW << endl;
    cout << "X/x: " << sameLetterX << endl;
    cout << "Y/y: " << sameLetterY << endl;
    cout << "Z/z: " << sameLetterZ << endl;

    return 0;
}
