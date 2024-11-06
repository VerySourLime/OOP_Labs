#include <iostream>
using namespace std;
#include "list.h"
#include "pair.h"

int main()
{
    // system("chcp 1251>null");
    List<int> list1(5);
    List<float> list2(5);
    List<double> list3(5);
    List<Pair> list4(3);
    List<int> list5(5);

    cout << "list1 int\n";
    cin >> list1;
    cout << list1;
    cout << "\nThe output of the element 1: ";
    cout << list1[0] << "\n";

    cout << "\nlist2 float\n";
    cin >> list2;
    cout << list2;
    cout << "\nThe output of the element 3: ";
    cout << list2[2] << "\n";

    cout << "\nlist3 double\n";
    cin >> list3;
    cout << list3 << "\n";

    cout << "\nlist4 Pair\n";
    cin >> list4;
    cout << list4;
    cout << "\nThe output of the element 2:\n";
    cout << list4[1] << "\n";

    cout << "\nlist5 = list1\n";
    list5 = list1;
    cout << list5 << "\n";

    return 0;
}