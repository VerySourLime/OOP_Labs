#include <iostream>
#include <string>

using namespace std;

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
    cout << "The constructor with parameters for the object was called " << this << endl;
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
           << "Year of study: " << student.year_of_study << endl
           << endl;
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

void Student::setName(const string name)
{
    this->Person::name = name;
}

void Student::setAge(const int age)
{
    this->Person::age = age;
}

void Person::setName(const string name)
{
    this->name = name;
}

void Person::setAge(const int age)
{
    this->age = age;
}

void Person::output()
{
    cout << "\tInformation about person:\nname: " << this->name << endl
         << "age: " << this->age << "\n\n";
}

void Student::output()
{
    cout << "\tInformation about student:\nname: " << this->name << endl
         << "age: " << this->age << endl
         << "Year of study: " << this->year_of_study << "\n\n";
}

string Person::getName()
{
    return this->name;
}

int Person::getAge()
{
    return this->age;
}

string Student::getName()
{
    return this->name;
}

int Student::getAge()
{
    return this->age;
}