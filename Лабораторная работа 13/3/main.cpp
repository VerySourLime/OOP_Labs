#include <iostream>
#include <functional>
#include "pair.h"
#include <map>
#include <time.h>

class Map : public map<Pair, Pair>
{};

using namespace std;

void randomize(Pair &);
void generate_M(Map &, int);
ostream &operator<<(ostream &, const pair<Pair, Pair>);
ostream &operator<<(ostream &, const Map &);
bool isInRange(Pair &, Pair &, Pair &);
void remove_from_range(Map &, Pair &, Pair &);
void all_sum(Map &, Pair &, Pair &);
Map substr_to_all(Map &, Pair &, Pair &);
bool findPair(Map &, Pair &, Pair &);

int main()
{
    srand(time(0));
    int map_size;

    cout << "Enter the size of the dictionary: ";
    cin >> map_size;

    Pair sum_1(0, 0), sum_2(0, 0), sum_key(0, 0), sum_value(0, 0);
    Map my_map;
    generate_M(my_map, map_size);
    cout << "Generated dictionary:\n"
         << my_map << "\n";

    all_sum(my_map, sum_1, sum_2);
    Pair average_key(sum_1.getFirst() / my_map.size(), sum_1.getSecond() / my_map.size());
    Pair average_value(sum_2.getFirst() / my_map.size(), sum_2.getSecond() / my_map.size());
    cout << "The arithmetic mean of the keys " << average_key << "\n";
    cout << "The arithmetic mean of the values " << average_value << "\n\n";
    my_map[average_key] = average_value;
    cout << "Adding an arithmetic mean:\n"
         << my_map << "\n";

    Pair temp_first_p, temp_second_p;
    cout << "Enter two pairs of numbers (keys), from the range of which the dictionary elements will be removed:\n";
    cin >> temp_first_p >> temp_second_p;
    if (temp_first_p > temp_second_p)
    {
        swap(temp_first_p, temp_second_p);
    }
    remove_from_range(my_map, temp_first_p, temp_second_p);
    cout << "\nResult:\n"
         << my_map << "\n";

    cout << "The arithmetic mean of the keys " << average_key << "\n";
    cout << "The arithmetic mean of the values " << average_value << "\n\n";
    my_map = substr_to_all(my_map, average_key, average_value);
    cout << "After subtracting the arithmetic mean from each dictionary element:\n";
    cout << my_map << "\n";

    cout << "Enter the key value by which you want to find the pair:\n";
    cin >> temp_first_p;
    bool found = findPair(my_map, temp_first_p, temp_second_p);
    cout << "\n";
    if (found)
    {
        cout << "The element is found.\n";
        cout << temp_first_p << " -> " << temp_second_p << "\n";
    }
    else
    {
        cout << "The element was not found.\n";
    }
    return 0;
}

ostream &operator<<(ostream &stream, const pair<Pair, Pair> p)
{
    stream  << p.first << "\t-> " << p.second << "\n";
    return stream;
}

ostream &operator<<(ostream &stream, const Map &t_map)
{
    Map::const_iterator Iter = t_map.begin();
    while (Iter != t_map.end())
    {
        cout << *Iter++;
    }
    return stream;
}

bool isInRange(Pair &key, Pair &lower, Pair &upper)
{
    return key > lower && key < upper;
}

void remove_from_range(Map &t_map, Pair &range_1, Pair &range_2)
{
    auto iterator = t_map.begin();
    Pair key;
    while (iterator != t_map.end())
    {
        key = iterator->first;
        if (!isInRange(key, range_1, range_2))
        {
            ++iterator;
        }
        else
        {
            iterator = t_map.erase(iterator);
        }
    }
}



void all_sum(Map &t_map, Pair &key, Pair &value)
{
    for (const auto &t_pair : t_map)
    {
        Pair tmp = t_pair.first;
        key = key + tmp;
        tmp = t_pair.second;
        value = value + tmp;
    }
}

Map substr_to_all(Map &t_map, Pair &key, Pair &value)
{
    Map tmp_map;
    for (const auto &t_pair : t_map)
    {
        Pair tmp_key = t_pair.first;
        Pair tmp_value = t_pair.second;
        tmp_map[tmp_key - key] = (tmp_value - value);
    }
    return tmp_map;
}

bool findPair(Map &t_map, Pair &key, Pair &value)
{
    auto iter = t_map.find(key);
    if (iter != t_map.end())
    {
        value = Pair(iter->second);
        return true;
    }
    else
    {
        return false;
    }
}

void randomize(Pair &p)
{
    int x = rand() % 1001;
    double y = (rand() % 100001) * 0.01;
    p = Pair(x, y);
}

void generate_M(Map &t_map, int M_size)
{
    Pair qwe_1(0, 0), qwe_2(0, 0);
    for (int i = 0; i < M_size; i++)
    {
        randomize(qwe_1);
        randomize(qwe_2);
        t_map[qwe_1] = qwe_2;
    }
}