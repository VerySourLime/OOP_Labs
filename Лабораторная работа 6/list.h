#pragma once
#include <iostream>
#include <vector>
#include "Node.h" // Включаем Node.h для структуры Node

class List {
public:
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;

    void pop_front();
    void push_back(int);
    void push_front(int);
    void pop_back();
    Node *getAt(int);
    void insert(int, int);
    void erase(int);
    void print();

    ~List();
    int &operator[](int);
    List &operator()(int);
    List &operator+=(int);

    friend List &operator*(List &a, std::vector<int> b);
};
