#include <iostream>
using namespace std;

#include "Pair.h"

int main()
{
    Pair a(1, 5.5);
    Pair b;
    a.get();
    cout << endl;
    b.get();
    cout << endl;
    b.set(6, 2.2);
    cout << endl << a << endl << b<< endl;
    cout << endl << (a > b);
    cout << endl << (a < b);
}
