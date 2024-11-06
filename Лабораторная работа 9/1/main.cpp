#include <iostream>
#include <vector>

#include "List.h"
#include "List.cpp"
#include "iterator.cpp"
#include "iterator.h"


using namespace std;

int main()
{
    cout << "Enter size of list: ";
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
    }
    catch (int)
    {
        cout << "The size must be non-negative!";
    }
    catch (char)
    {
        cout << "Maximum size - 30!";
    }
    catch (float)
    {
        cout << "Index must be non-negative!";
    }
    catch (double)
    {
        cout << "Index must be in list-size range!";
    }
}
