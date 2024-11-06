#pragma once
#include "Cost.h"


Dialog::Dialog(unsigned int first, double second)
{
    cout << "Calling the class constructor Dialog\n";
	first = first;
	second = second;
}

void Dialog::cost()
{
	cout << "Total amount of the call: " << first*second << endl;
}

void Dialog::setFirst(unsigned int a0)
{
	cout << "Number of minutes of call = " << a0 << endl;
	first = a0;
}

void Dialog::setSecond(double r)
{
	cout << "Cost of one minute of call = " << r << endl;
	second = r;
}
