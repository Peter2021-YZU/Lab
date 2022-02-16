#include <iostream>
#include <cmath>

using namespace std;


int foo(int);
long long int factorial(int);


int main()
{
    cout << foo( 4 ) << '\n'; // 6
    cout << foo( 6 ) << '\n'; // 20
    cout << foo( 8 ) << '\n'; // 70
    cout << foo( 10 ) << '\n'; // 252
    cout << foo( 12 ) << '\n'; // 924
    cout << foo( 14 ) << '\n'; // 3432
    cout << foo( 16 ) << '\n'; // 12870
    cout << foo( 18 ) << '\n'; // 48620
    cout << foo( 20 ) << '\n'; // 184756
}

int foo(int number)
{
    int answer = 0;
    int size = number/2;
    answer = factorial(number) / (factorial(number-size) * factorial(size));
    return answer;
}

long long int factorial(int number)
{
    long long int factor = 1;
    for(int i = 1; i <= number; ++i){
        factor *= i;
    }
    return factor;
}
