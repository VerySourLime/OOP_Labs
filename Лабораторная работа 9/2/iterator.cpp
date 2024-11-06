#pragma once

#include <iostream>
#include <string>

#include "iterator.h"
#include "list.h"

using namespace std;

Node *Iterator::getNode()
{
    return this->iter;
}

Iterator::Iterator(List &a)
{
    this->iter = a.head;
}

Node *Iterator::operator+(int a)
{
    Node *iter = this->iter;
    for (int i = 0; i < a; ++i)
        iter = iter->next_ptr;
    return iter;
}

Node *Iterator::operator++()
{
    iter = iter->next_ptr;
    return iter;
}

Node *Iterator::operator++(int)
{
    iter = iter->next_ptr;
    return iter;
}