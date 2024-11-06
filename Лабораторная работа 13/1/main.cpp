#include <list>
#include "pair.h"
#include "List.h"
#include <functional>
#include <iostream>

using namespace std;

int main() {
    double sum1 = 0;
    double sum2 = 0;

    List my_list;
    int temp_int;
    Pair temp_pair;
    Pair temp_pair2;

    cout << "\nEnter amount of elements: ";
    cin >> temp_int;
    my_list.fill_list(temp_int);
    my_list.print();

    // вычисление среднего арифметического
    std::for_each(my_list.begin(), my_list.end(), [&sum1, &sum2](const Pair& p) {
        sum1 += p.getFirst();
        sum2 += p.getSecond();
    });

    double average1 = sum1 / temp_int;
    double average2 = sum2 / temp_int;
    temp_pair.set(average1, average2);
    cout << "\nArithmetic mean of pairs: " << temp_pair << endl;

    cout << "\nEnter the position to insert the arithmetic mean of pairs: ";
    cin >> temp_int;
    my_list.insert_pair(temp_int, temp_pair);
    my_list.print();

    cout << "\nEnter two pairs of numbers to remove from the list: ";
    cin >> temp_pair >> temp_pair2;
    if (temp_pair2 < temp_pair) {
        swap(temp_pair, temp_pair2);
    }

    auto s = remove_if(my_list.begin(), my_list.end(), [&temp_pair, &temp_pair2](const Pair& p) {
        return (temp_pair <= p) && (p <= temp_pair2);
    });
    my_list.erase(s, my_list.end());
    my_list.print();

    cout << "\nAdding arithmetic mean to each element:\n";
    std::for_each(my_list.begin(), my_list.end(), [&average1, &average2](Pair& p) {
        p.set(p.getFirst() + average1, p.getSecond() + average2);
    });
    my_list.print();

    cout << "\nSort in Descending order:";
    my_list.sort([](const Pair& a, const Pair& b) { return a > b; });
    my_list.print();

    cout << "\nSort in Ascending order:";
    my_list.sort([](const Pair& a, const Pair& b) { return a < b; });
    my_list.print();

    cout << "\nEnter the value to find the pair: ";
    cin >> temp_pair;
    temp_int = 0;
    s = find_if(my_list.begin(), my_list.end(), [&temp_pair, &temp_int](const Pair& p) {
        temp_int++;
        return temp_pair == p;
    });
    if (s != my_list.end()) {
        cout << "Element has been found, its number: " << temp_int << endl;
    } else {
        cout << "Element not found." << endl;
    }
}