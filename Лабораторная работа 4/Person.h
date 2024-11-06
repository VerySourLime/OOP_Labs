#pragma once

#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
	string name;
	int age;

public:
	Person();
	Person(string, int);
	Person(const Person &);
	~Person();
	void setName(const string);
	void setAge(const int);
	void operator=(const Person &);
	friend ostream &operator<<(ostream &, Person &);
	friend istream &operator>>(istream &, Person &);
};

class Student : public Person
{
protected:
	int year_of_study;

public:
	Student();
	Student(string, int, int);
	void setYoS(int);
	Student &operator++();
	Student &operator++(int);
	friend ostream &operator<<(ostream &, const Student &);
	friend istream &operator>>(istream &, Student &);
};

Student &Student::operator++()
{
	++this->year_of_study;
	return *this;
}

Student &Student::operator++(int)
{
	this->year_of_study++;
	return *this;
}

Person::Person()
{
	cout << "The constructor without parameters for the object was called " << this << endl;
	this->name = "-";
	this->age = 0;
}

Person::Person(string name, int age)
{
	cout << "The constructor with the parameters for the object was called " << this << endl;
	this->name = name;
	this->age = age;
}

Person::Person(const Person &other)
{
	cout << "The copy constructor for the object was called " << this << endl;
	this->name = other.name;
	this->age = other.age;
}

Person::~Person()
{
	cout << "The destructor for the object was called " << this << endl;
}

void Person::setName(const string name)
{
	this->name = name;
}

void Person::setAge(const int age)
{
	this->age = age;
}

void Person::operator=(const Person &person)
{
	this->name = person.name;
	this->age = person.age;
}

ostream &operator<<(ostream &stream, Person &person)
{
	stream << "name: " << person.name << endl
		   << "age: " << person.age << "\n\n";
	return stream;
}

istream &operator>>(istream &stream, Person &person)
{
	string name;
	int age;
	cout << "Enter name: ";
	cin.seekg(cin.eof());
	getline(cin, name);
	cout << "Enter age: ";
	cin >> age;
	person.setName(name);
	person.setAge(age);
	return stream;
}

Student::Student()
{
	this->name = "-";
	this->age = 0;
	this->year_of_study = 0;
}

Student::Student(string name, int age, int yos)
{
	this->name = name;
	this->age = age;
	this->year_of_study = yos;
}

void Student::setYoS(int yos)
{
	this->year_of_study = yos;
}

ostream &operator<<(ostream &stream, const Student &student)
{
	stream << "name: " << student.name << endl
		   << "age: " << student.age << endl
		   << "Year of study: " << student.year_of_study << endl << endl;
	return stream;
}

istream &operator>>(istream &stream, Student &student)
{
	
	string name;
	int yos, age;
	cout << "Enter name: ";
	cin.seekg(cin.eof());
	getline(stream, student.name);
	cout << "Enter age: ";
	stream >> age;
	student.age = age;
	cout << "Enter year of study: ";
	stream >> yos;
	student.setYoS(yos);
	return stream;
}
