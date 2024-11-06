#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include "Pair.h"
#include "P_queue.h"
#include "time.h"
using namespace std;

ostream &operator<<(ostream &, priority_queue<Pair, vector<Pair>, Pair_increase>);
Pair all_sum(priority_queue<Pair, vector<Pair>, Pair_increase>);

int main()
{
    srand(time(0));
    int q_size;
    cout << "Enter size of queue: ";
    cin >> q_size;

    P_queue my_queue;
    my_queue.generate_Q(q_size);
    cout << my_queue;

    Pair sum = all_sum(my_queue);
    Pair average(sum.getFirst() / my_queue.size(), sum.getSecond() / my_queue.size());
    cout << "\nArithmetic mean: " << average << "\n\n";
    
    my_queue.push(sum);
    cout << "After adding the arithmetic mean:\n"
         << my_queue << "\n";

    Pair first_p, second_p;
    cout << "Enter two pairs of numbers from which the list items will be removed:\n";
    cout << "First pair:\n";
    cin >> first_p;
    cout << "Second pair:\n";
    cin >> second_p;

    if (first_p > second_p)
    {
        swap(first_p, second_p);
    }
    my_queue.remove_from_range(first_p, second_p);
    cout << "\nAfter being removed from the range:\n"
         << my_queue << "\n";

    my_queue.substr_to_all(average);
    cout << "After subtracting the arithmetic mean " << average << " :\n"
         << my_queue;

    cout << "Enter the pair value by which you want to find the pairу: ";
    Pair tmp_pair;
    cin >> tmp_pair;
    int index = my_queue.find_pair(tmp_pair);
    if (index)
        cout << "The item has been found, its number: " << index + 1 << "\n";
    else
        cout << "Element not found. \n";
    return 0;
}

Pair all_sum(priority_queue<Pair, vector<Pair>, Pair_increase> temp_Q)
{
    Pair sum(0, 0);
    while (!temp_Q.empty())
    {
        Pair top_pair = temp_Q.top();
        sum = sum + top_pair;
        temp_Q.pop();
    }
    return sum;
}
