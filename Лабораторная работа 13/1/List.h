#pragma once
#include <iostream>
#include <list>
#include "pair.h"

using namespace std;

class List : public list<Pair> {
public:
    void print() const {
        if (empty()) {
            cout << "List is empty!\n";
            return;
        }
        for (const auto& pair : *this) {
            cout << pair << ' ';
        }
        cout << endl;
    }

    void fill_list(int n) {
        Pair temp_pair;
        for (int i = 0; i < n; i++) {
            cin >> temp_pair;
            push_back(temp_pair);
        }
    }

    void insert_pair(int k, const Pair& temp_pair) {
        auto iter = begin();
        advance(iter, k - 1);
        insert(iter, temp_pair);
    }
};
