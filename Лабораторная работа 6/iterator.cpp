#include <iostream>
#include "Iterator.h"

using namespace std;

Node *Iterator::getNode() {
    return this->iter;
}

Iterator::Iterator(List &a) {
    this->iter = a.head;
}

Node *Iterator::operator+(int a) {
    Node *temp = this->iter;
    for (int i = 0; i < a && temp; ++i) {
        temp = temp->next_ptr;
    }
    return temp;
}

Node *Iterator::operator++() {
    if (iter) {
        iter = iter->next_ptr;
    }
    return iter;
}

Node *Iterator::operator++(int) {
    Node *oldIter = iter;
    if (iter) {
        iter = iter->next_ptr;
    }
    return oldIter;
}
