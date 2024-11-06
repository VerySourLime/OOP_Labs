#include <iostream>
#include <vector>

#include "Object.h"
#include "Object1.h"

using namespace std;

int main()
{
    vector<Object *> vect;
    Person person;
    Student student;
    cout << "Initializing an object of the Person class:\n";
    cin >> person;
    cout << "Entered data:\n";
    cout << person;
    cout << "Initializing an object of the Student class:\n";
    cin >> student;
    cout << "Entered data:\n";
    cout << student;
    vect.push_back(&person);
    vect.push_back(&student);
    cout << endl
         << endl;
    for (int i = 0; i < int(vect.size()); i++)
    {
        vect[i]->output();
    }
}