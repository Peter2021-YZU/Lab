#include <iostream>



using namespace std;

long long int factorial(int a)
{
    long long int factor = 1;
    int i = 1;
    while( i <= a ){
        factor *= i;
        i++;
    }
    return factor;
}

int main()
{
  int a = 4;
  int b = 34;


  cout << factorial(a) << "-----" << factorial(b) << endl;


  return 0;
}
