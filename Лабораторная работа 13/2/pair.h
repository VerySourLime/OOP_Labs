#pragma once
#include <iostream>
using namespace std;

class Pair
{
private:
    int first;
    double second;

public:
    Pair();
    Pair(int, double);
    Pair(const Pair &);
    ~Pair(){};

    int getFirst();
    double getSecond();
    bool operator<(Pair &);
    bool operator>(Pair &);
    bool operator<=(Pair &);
    bool operator>=(Pair &);
    Pair &operator++();
    Pair &operator+(const Pair &);
    Pair &operator-(const Pair &);
    Pair &operator++(int);
    friend ostream &operator<<(ostream &out, Pair i);
    friend istream &operator>>(istream &stream, Pair &pair);
    void operator=(const Pair &);
    bool operator==(const Pair &);
    void get();
    void set(int, double);
};

int Pair::getFirst()
{
    return this->first;
}

double Pair::getSecond()
{
    return this->second;
}

Pair::Pair()
{
    this->first = 0;
    this->second = 0;
}

Pair::Pair(int fir, double sec)
{
    this->first = fir;
    this->second = sec;
}

Pair::Pair(const Pair &copying)
{
    this->first = copying.first;
    this->second = copying.second;
}

bool Pair::operator<(Pair &temp)
{
    if ((this->first + this->second) < (temp.first + temp.second))
        return true;
    return false;
}

bool Pair::operator<=(Pair &temp)
{
    if ((this->first + this->second) <= (temp.first + temp.second))
        return true;
    return false;
}

bool Pair::operator>(Pair &temp)
{
    if ((this->first + this->second) > (temp.first + temp.second))
        return true;
    return false;
}

bool Pair::operator>=(Pair &temp)
{
    if ((this->first + this->second) >= (temp.first + temp.second))
        return true;
    return false;
}

Pair &Pair::operator++()
{
    ++this->first;
    return *this;
}

Pair &Pair::operator++(int)
{
    ++this->second;
    return *this;
}

void Pair::get()
{
    std::cout << "first = " << this->first << ", second = " << this->second;
}

void Pair::set(int fir, double sec)
{
    this->first = fir;
    this->second = sec;
}

ostream &operator<<(ostream &pairout, Pair temp)
{
    return (pairout << temp.first << ':' << temp.second);
}

istream &operator>>(istream &stream, Pair &pair)
{
    int first;
    double second;
    stream >> first >> second;
    pair.first = first;
    pair.second = second;
    return stream;
}

void Pair::operator=(const Pair &other)
{
    this->first = other.first;
    this->second = other.second;
}

bool Pair::operator==(const Pair &other)
{
    if (this->first == other.first && this->second == other.second)
        return true;
    else
        return false;
}

Pair &Pair::operator+(const Pair & add_pair)
{
    this->first += add_pair.first;
    this->second += add_pair.second;
    return *this;
}

Pair &Pair::operator-(const Pair & subst_pair)
{
    this->first -= subst_pair.first;
    this->second -= subst_pair.second;
    return *this;
}
