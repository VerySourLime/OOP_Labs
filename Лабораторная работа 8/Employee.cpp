#pragma once

#include "Classes.h"

Employee::Employee() : Person()
{
    this->salary = 0;
    this->post = "";
}

Employee::Employee(string name, int age, float salary, string post) : Person(name, age)
{
    this->age = age;
    this->post = post;
}

Employee::Employee(const Employee &other_employee)
{
    this->age = other_employee.age;
    this->Name = other_employee.Name;
    this->salary = other_employee.salary;
}

void Employee::Show(bool names = false)
{
    if (!names)
    {
        cout << "\nName: " << this->Name << " Age: " << this->age
             << "\nSalary: " << this->salary << " Post: " << this->post << "\n\n";
    }
    else
    {
        cout << "\nName: " << this->Name << "\n\n";
    }
}

void Employee::Input()
{
    cout << "\nEnter data of worker:\n";
    cout << "Name: ";
    cin.seekg(cin.eof());
    getline(cin, this->Name);
    cout << "Age: ";
    cin >> this->age;
    cout << "Salary: ";
    cin >> this->salary;
    cout << "Post: ";
    cin.seekg(cin.eof());
    getline(cin, this->post);

}

Employee &Employee::operator=(const Employee &other_employee)
{
    if (this == &other_employee)
    {
        return *this;
    }
    Person::operator=(other_employee);
    this->salary = other_employee.salary;
    this->post = other_employee.post;
    return *this;
}
