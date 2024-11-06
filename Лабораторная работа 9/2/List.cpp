#pragma once
#include <iostream>
#include <vector>
#include "list.h"
#include "iterator.h"
#include "errors.h"

using namespace std;

const int MAX_SIZE = 30;

List::List(int k)
{
    if (k > MAX_SIZE) throw ErrorSizeIsTooBig();
    if (k < 0) throw ErrorSizeIsTooSmall();
    size = k;
    for (int i = 0; i < k; i++)
    {
        this->push_back(0);
    }
}

void List::pop_front()
{
    if (head == nullptr)
        return;
    if (head == tail)
    {
        delete tail;
        head = tail = nullptr;
        return;
    }
    Node *node = head;
    head = node->next_ptr;
    delete node;
    --size;
}

void List::push_back(int data)
{
    Node *node = new Node;
    node->data = data;
    if (head == nullptr)
        head = node;
    if (tail != nullptr)
        tail->next_ptr = node;
    tail = node;
    ++size;
}

void List::push_front(int data)
{
    Node *node = new Node;
    node->data = data;
    node->next_ptr = head;
    head = node;
    if (tail == nullptr)
        tail = node;
    ++size;
}

void List::pop_back()
{
    if (tail == nullptr)
        return;
    if (head == tail)
    {
        delete tail;
        head = tail = nullptr;
        return;
    }
    Node *node = head;
    for (; node->next_ptr != tail; node = node->next_ptr)
        ;
    node->next_ptr = nullptr;
    delete tail;
    tail = node;
    --size;
}

Node *List::getAt(int k)
{
    if (k < 0)
        return 0;

    Node *node = head;
    int n = 0;
    while (node && n != k && node->next_ptr)
    {
        node = node->next_ptr;
        n++;
    }
    if (n == k)
        return node;
    else
        return nullptr;
}

void List::insert(int k, int data)
{
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

void List::erase(int k)
{
    if (k < 0)
        return;
    if (k == 0)
    {
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

void List::print()
{
    for (Iterator iterator(*this); iterator.getNode() != nullptr; iterator++) // вывод
        cout << iterator.getNode()->data << ' ';
    cout << endl
         << endl;
}

List &List::operator+=(int k)
{
    for (Iterator iterator(*this); iterator.getNode() != nullptr; iterator++) // вывод
        iterator.getNode()->data += k;
    return *this;
}

List &List::operator++(int)
{
    this->push_back(0);
    return *this;
}

List::~List()
{
    while (head != nullptr)
        pop_front();
}

int &List::operator[](int a)
{   
    if (a >= this->size) throw ErrorIndexIsTooBig();
    if (a < 0) throw ErrorIndexIsTooSmall();
    return getAt(a)->data;
}

List &List::operator()(int k)
{
    if (k > MAX_SIZE) throw ErrorSizeIsTooBig();
    if (k < 0) throw ErrorSizeIsTooSmall();
    while (size > k)
    {
        this->pop_back();
        size--;
    }
    while (size < k)
    {
        this->push_back(0);
    }
    return *this;
}