#pragma once

#include <iostream>
#include <string>
#include "Event.h"
using namespace std;

class Object
{
public:
    Object() {}
    virtual ~Object() {}
    virtual void Show(bool) = 0;
    virtual void Input() = 0;
};

class Person : public Object
{
protected:
    string Name;
    int age;

public:
    Person();
    Person(string, int);
    Person(const Person &);
    virtual ~Person() {}
    void Show(bool) override;
    void Input() override;
    Person &operator=(const Person &);
    void setAge(int &age) { this->age = age; }
    void setName(string &name) { this->Name = name; }
    int getAge() { return this->age; }
    string getName() { return this->Name; }
};

class Employee : public Person
{
protected:
    float salary;
    string post;

public:
    Employee();
    Employee(string, int, float, string);
    Employee(const Employee &);
    ~Employee() {}
    void Show(bool) override;
    void Input() override;
    Employee &operator=(const Employee &);

    void setPages(float &salary) { this->salary = salary; }
    float getPages() { return this->salary; }
};
