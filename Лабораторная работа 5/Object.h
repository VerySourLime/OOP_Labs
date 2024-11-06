#pragma once

#include <iostream>
#include <string>

using namespace std;

class Object
{
public:
	Object(){};
	virtual ~Object(){};
	virtual void output() = 0;
	virtual void setName(const string) = 0;
	virtual void setAge(const int) = 0;
	virtual string getName() = 0;
	virtual int getAge() = 0;
};

class Person : public Object
{
protected:
	string name;
	int age;

public:
	Person();
	Person(string, int);
	Person(const Person &);
	~Person();

	void operator=(const Person &);
	friend ostream &operator<<(ostream &, Person &);
	friend istream &operator>>(istream &, Person &);
	void setName(const string) override;
	void setAge(const int) override;
	void output() override;
	string getName() override;
	int getAge() override;
};

class Student : public Person
{
protected:
	int year_of_study;

public:
	Student();
	Student(string, int, int);
	void setYoS(int);
	string getName() override;
	int getAge() override;
	Student &operator++();
	Student &operator++(int);

	void setName(const string) override;
	void setAge(const int) override;
	void output() override;
	friend ostream &operator<<(ostream &, const Student &);
	friend istream &operator>>(istream &, Student &);
};