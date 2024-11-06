#pragma once
#include <iostream>
using namespace std;


class Dialog
{
private:
	unsigned int first;
	double second;
public:
	Dialog(unsigned int, double);
	void cost();
	void setFirst(unsigned int);
	void setSecond(double);
};