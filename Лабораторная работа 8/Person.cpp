#pragma once

using namespace std;

#include "Classes.h"

Person::Person()
{
	this->age = 0;
	this->Name = "NoName";
}

Person::Person(string name, int age)
{
	this->age = age;
	this->Name = name;
}

Person::Person(const Person &other)
{
	this->Name = other.Name;
	this->age = other.age;
}

void Person::Show(bool names = false)
{
	if (!names)
	{
		cout << "\nName: " << this->Name << " Age: " << this->age << "\n\n";
	}
	else
	{
		cout << "Name: " << this->Name << "\n";
	}
}

void Person::Input()
{
	cout << "\nEnter personal data\n";
	cout << "name: ";
	cin.seekg(cin.eof());
	getline(cin, this->Name);
	cout << "Age: ";
	int temp;
	cin >> temp;
	this->age = temp;
}

Person &Person::operator=(const Person &other_Print)
{
	if (&other_Print == this)
	{
		return *this;
	}
	this->Name = other_Print.Name;
	this->age = other_Print.age;
	return *this;
}