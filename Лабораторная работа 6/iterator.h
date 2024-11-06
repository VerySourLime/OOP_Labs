#pragma once
#include "List.h"

class Iterator {
private:
    Node *iter;

public:
    Node *getNode();

    Iterator(List &a);
    Node *operator+(int a);
    Node *operator++();
    Node *operator++(int);
};
