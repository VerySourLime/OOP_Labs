#pragma once
#include <queue>
#include "pair.h"
#include <functional>

class Pair_increase
{
public:
    bool operator()(Pair &p1, Pair &p2)
    {
        return p1 < p2;
    }
};

class P_queue : public std::priority_queue<Pair, vector<Pair>, Pair_increase>
{
private:
    void randomize(Pair &p)
    {
        int x = rand() % 1001;
        double y = (rand() % 100001) * 0.01;
        p = Pair(x, y);
    }

public:
    void generate_Q(int size)
    {
        Pair tmp(0, 0);
        for (int i = 0; i < size; i++)
        {
            randomize(tmp);
            this->push(tmp);
        }
    }

    void remove_from_range(Pair &range_1, Pair &range_2)
    {
        P_queue queue_1;
        while (!this->empty())
        {
            Pair top_pair = this->top();
            if (!(top_pair > range_1 && top_pair < range_2))
            {
                queue_1.push(top_pair);
            }
            this->pop();
        }
        *this = queue_1;
    }

    void substr_to_all(Pair &pair)
    {
        P_queue queue_1;
        Pair top_pair = this->top();
        while (!this->empty())
        {
            top_pair = this->top();
            queue_1.push(top_pair - pair);
            this->pop();
        }
        *this = queue_1;
    }

    int find_pair(Pair &need_p)
    {
        Pair tmp_pair;
        int cnt = this->size();
        int index = -1;
        while (!this->empty())
        {
            tmp_pair = this->top();
            if (tmp_pair == need_p)
            {
                index = cnt;
                return index;
            }
            this->pop();
            cnt--;
        }
        return index;
    }

    friend ostream &operator<<(ostream &stream, priority_queue<Pair, vector<Pair>, Pair_increase> queue)
    {
        while (!queue.empty())
        {
            Pair user = queue.top();
            cout << user << endl;
            queue.pop();
        }
        return stream;
    }
};