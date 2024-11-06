#include <iostream>
#include <vector>

#include "List.h"
#include "List.cpp"
#include "iterator.cpp"
#include "iterator.h"
#include "errors.h"


using namespace std;

int main()
{
    cout << "Enter list size: ";
    try
    {
        int temp_int;
        cin >> temp_int;

        List list(temp_int);

        for (Iterator iterator(list); iterator.getNode() != nullptr; iterator++) // вывод
        {
            cin >> temp_int;
            iterator.getNode()->data = temp_int;
        }
        list.print();
        cout << "First element of list: ";
        cout << list[0] << endl;
        cout << "Invalid operations:\n";
        cout << list[-3] << endl;
        // cout << list[60] << endl;
        // cout << list[list.size] << endl;
        // list(34);
    }
    catch (Error &error)
    {
        error.what();
    }
}