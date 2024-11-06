#include <iostream>
#include <fstream>

#include "Pair.h"
#include "Pair.cpp"
#include "file_work.h"
#include <time.h>
using namespace std;

int main() 
{
	// system("chcp 1251 > Null");
	srand(time(0));
	int N;
	do
	{
		cout << "Enter ammount of elements: ";
		cin >> N;
	} while (N < 1);

	cout << "\n";

	write_to_a_file(N);

	bool isRunning = true;
	while (isRunning) 
	{
		int current_action = choosing_an_action();
		int tmp_int;
		double tmp_double;

		Pair pair;
		switch (current_action) 
		{
		case 1:
			cout << "Current file data:\n";
			print_file();
			cout << endl;
			break;
		case 2:
			do 
			{
				cout << "Enter ammount of elements: ";
				cin >> tmp_int;
			} while (tmp_int < 1);
			write_to_a_file(tmp_int);
			break;
		case 3:
			cout << "Enter minimal pair value (int double):\n";
			cin >> pair;
			removing_el_smaller_than(pair);
			break;
		case 4:
			do 
			{
				cout << "Which number you want to enter?\n";
				cout << "1 - integer \n2 - real\n";
				cin >> N;
			} while (N < 1 || N>2);
			switch (N) 
			{
			case 1:
				cout << "Enter integer number: ";
				cin >> tmp_int;
				add_L(tmp_int);
				break;
			default:
				cout << "Enter real number: ";
				cin >> tmp_double;
				add_L(tmp_double);
				break;
			}
			break;
		case 5:
			do 
			{
				cout << "Enter the NUMBER after which you need to enter k elements\n";
				cin >> N;
			} while (N < 1);

			do 
			{
				cout << "Enter the number of elements to be added\n";
				cin >> tmp_int;
			} while (tmp_int < 1);
			add_k_el_after(N, tmp_int);
			break;
		default:
			isRunning = false;
			break;
		}
	}
	return 0;
}