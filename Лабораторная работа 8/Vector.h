#pragma once
#include "Classes.h"
#include <iostream>
using namespace std;


class Vector
{
protected:
	Object **begin;
	int size;
	int current_position;

public:
	Vector();
	Vector(int);
	~Vector();
	void Add();
	void Del();
	void print(bool);
	void create(int);
	void resize(int);
	int operator()();
	friend ostream &operator<<(ostream &, const Vector &);
};