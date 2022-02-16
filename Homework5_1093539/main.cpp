#include <iostream>

using namespace std;

template< typename number >

//void mySwap( number &c, number &d )
//{
//    number temp;
//    temp = c;
//    c = d;
//    d = temp;
//}

void mySwap( number &c, number &d )
{
   c = c + d;
   d = c - d;
   c = c - d;
}


int main()
{
     int a = 3;
     int b = 6;
     mySwap( a, b );
     double x = 3.2;
     double y = 3.7;
     mySwap( x, y );
     cout << a << ' ' << b << ' '; // 6 3
     cout << x << ' ' << y << '\n'; // 3.7 3.2
}
