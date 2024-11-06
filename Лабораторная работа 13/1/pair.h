#pragma once
#include <iostream>
using namespace std;

class Pair {
private:
    int first;
    double second;

public:
    Pair();
    Pair(int, double);
    Pair(const Pair&);
    ~Pair() = default;

    int getFirst() const;
    double getSecond() const;
    bool operator<(const Pair&) const;
    bool operator>(const Pair&) const;
    bool operator<=(const Pair&) const;
    bool operator>=(const Pair&) const;
    Pair& operator++();
    Pair& operator++(int);
    friend ostream& operator<<(ostream& out, const Pair& i);
    friend istream& operator>>(istream& stream, Pair& pair);
    Pair& operator=(const Pair&);
    bool operator==(const Pair&) const;
    void set(int, double);
};

inline int Pair::getFirst() const {
    return first;
}

inline double Pair::getSecond() const {
    return second;
}

inline Pair::Pair() : first(0), second(0) {}

inline Pair::Pair(int fir, double sec) : first(fir), second(sec) {}

inline Pair::Pair(const Pair& copying) : first(copying.first), second(copying.second) {}

inline bool Pair::operator<(const Pair& temp) const {
    return (first + second) < (temp.first + temp.second);
}

inline bool Pair::operator<=(const Pair& temp) const {
    return (first + second) <= (temp.first + temp.second);
}

inline bool Pair::operator>(const Pair& temp) const {
    return (first + second) > (temp.first + temp.second);
}

inline bool Pair::operator>=(const Pair& temp) const {
    return (first + second) >= (temp.first + temp.second);
}

inline Pair& Pair::operator++() {
    ++first;
    return *this;
}

inline Pair& Pair::operator++(int) {
    ++second;
    return *this;
}

inline void Pair::set(int fir, double sec) {
    first = fir;
    second = sec;
}

inline ostream& operator<<(ostream& pairout, const Pair& temp) {
    return (pairout << temp.first << ':' << temp.second);
}

inline istream& operator>>(istream& stream, Pair& pair) {
    stream >> pair.first >> pair.second;
    return stream;
}

inline Pair& Pair::operator=(const Pair& other) {
    if (this != &other) {
        first = other.first;
        second = other.second;
    }
    return *this;
}

inline bool Pair::operator==(const Pair& other) const {
    return (first == other.first && second == other.second);
}
