#include <iostream>
#include <vector>
#include "List.h"
#include "Iterator.h"

using namespace std;

void List::pop_front() {
    if (head == nullptr)
        return;
    if (head == tail) {
        delete tail;
        head = tail = nullptr;
        return;
    }
    Node *node = head;
    head = node->next_ptr;
    delete node;
    --size;
}

void List::push_back(int data) {
    Node *node = new Node;
    node->data = data;
    if (head == nullptr)
        head = node;
    if (tail != nullptr)
        tail->next_ptr = node;
    tail = node;
    ++size;
}

void List::push_front(int data) {
    Node *node = new Node;
    node->data = data;
    node->next_ptr = head;
    head = node;
    if (tail == nullptr)
        tail = node;
    ++size;
}

void List::pop_back() {
    if (tail == nullptr)
        return;
    if (head == tail) {
        delete tail;
        head = tail = nullptr;
        return;
    }
    Node *node = head;
    while (node->next_ptr != tail) {
        node = node->next_ptr;
    }
    node->next_ptr = nullptr;
    delete tail;
    tail = node;
    --size;
}

Node *List::getAt(int k) {
    if (k < 0)
        return nullptr;

    Node *node = head;
    for (int n = 0; node && n != k; ++n) {
        node = node->next_ptr;
    }
    return node;
}

void List::insert(int k, int data) {
    Node *left = getAt(k);
    if (left == nullptr)
        return;

    Node *right = left->next_ptr;
    Node *node = new Node;
    node->data = data;

    left->next_ptr = node;
    node->next_ptr = right;
    if (right == nullptr)
        tail = node;
    size++;
}

void List::erase(int k) {
    if (k < 0)
        return;
    if (k == 0) {
        pop_front();
        return;
    }

    Node *left = getAt(k - 1);
    Node *node = left->next_ptr;
    if (node == nullptr)
        return;

    Node *right = node->next_ptr;
    left->next_ptr = right;
    if (node == tail)
        tail = left;
    delete node;
    --size;
}

void List::print() {
    for (Iterator iterator(*this); iterator.getNode() != nullptr; iterator++) {
        cout << iterator.getNode()->data << ' ';
    }
    cout << endl << endl;
}

List &List::operator+=(int k) {
    for (Iterator iterator(*this); iterator.getNode() != nullptr; iterator++) {
        iterator.getNode()->data += k;
    }
    return *this;
}

List::~List() {
    while (head != nullptr)
        pop_front();
}

int &List::operator[](int a) {
    Node *node = getAt(a);
    if (node) {
        return node->data;
    }
    throw out_of_range("Index out of range"); // Обработка выхода за границы
}

List &List::operator()(int k) {
    while (size > k) {
        pop_back();
    }
    while (size < k) {
        push_back(0);
    }
    return *this;
}
