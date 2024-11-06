#pragma once
using namespace std;

void randomize(Pair& p) 
{
	int x = rand() % 1001;
	double y = (rand() % 100001) * 0.01;
	p = Pair(x, y);
}

bool write_to_a_file(int N) {
	fstream F1("labWork10.txt", ios::out | ios::trunc);
	if (!F1) 
	{
		cout << "File opening error\n";
		return 0;
	}

	for (int i = 0; i < N; i++) 
	{
		Pair pair;
		randomize(pair);
		F1 << pair << "\n";
	}
	F1.close();
	return 1;
}

bool print_file() 
{
	fstream F1("labWork10.txt", ios::in);
	//in чтение
	if (!F1) 
	{
		cout << "File opening error\n";
		return 0;
	}
	Pair pair;
	while (F1 >> pair) 
	{
		cout << pair << "\n";
	}
	return 1;
}
void error_mes(bool N) 
{
	if (!N) 
	{
		cout << "File not found\n";
	}
}

bool removing_el_smaller_than(Pair& para) 
{
	fstream F1("labWork10.txt", ios::in);
	//in чтение
	if (!F1) 
	{
		cout << "File opening error\n";
		return 0;
	}
	fstream tmp("temporary_file.txt", ios::out | ios::trunc);
	//out - перезаписывание
	//trunk - удалить старое содержимое файла (по умолчанию для оfstream) 
	Pair pair;
	while (F1 >> pair) 
	{
		if (pair > para) 
		{
			tmp << pair << "\n";
		}
	}
	F1.close();
	tmp.close();
	remove("labWork10.txt");
	rename("temporary_file.txt", "labWork10.txt");
	return 1;
}

template<typename T>
bool add_L(T L) 
{
	fstream F1("labWork10.txt", ios::in);
	//in чтение
	if (!F1) 
	{
		cout << "File opening error\n";
		return 0;
	}
	fstream tmp("temporary_file.txt", ios::out | ios::trunc);
	//out - перезаписывание
	//trunk - удалить старое содержимое файла (по умолчанию для оfstream) 
	Pair pair;
	while (F1 >> pair) 
	{
		pair = pair + L;
		tmp << pair << endl;
	}
	F1.close();
	tmp.close();
	remove("labWork10.txt");
	rename("temporary_file.txt", "labWork10.txt");
	return 1;
}

bool add_k_el_after(int number, int quantity) 
{
	fstream F1("labWork10.txt", ios::in);
	//in чтение
	if (!F1) 
	{
		cout << "File opening error\n";
		return 0;
	}
	fstream tmp("temporary_file.txt", ios::out | ios::trunc);
	//out - перезаписывание
	//trunk - удалить старое содержимое файла (по умолчанию для оfstream) 
	Pair pair;
	int counter = 0;
	while (F1 >> pair) 
	{
		counter++;
		tmp << pair << "\n";

		if (counter == number) 
		{
			for (int i = 0; i < quantity; i++) 
			{
				Pair new_pair;
				randomize(new_pair);
				tmp << new_pair << "\n";
			}
		}
	}
	if (counter < number)
		cout << "The end of the file has been reached! The element with the number" << number <<" not found\n";
	F1.close();
	tmp.close();
	remove("labWork10.txt");
	rename("temporary_file.txt", "labWork10.txt");
	return 1;
}

int choosing_an_action() 
{
	cout << "Select an action\n";
	cout << "1 - Output the contents of the file\n";
	cout << "2 - Overwrite the contents of the file\n";
	cout << "3 - Delete all entries less than the specified value\n";
	cout << "4 - ncrease all entries with the specified value by a number L\n";
	cout << "5 - Add K entries after the element with the specified number\n";
	cout << "0 - End of work\n";
	int choice;
	do 
	{
		cout << ">  ";
		cin >> choice;
	} while (choice < 0 || choice > 6);
	cout << "\n";
	return choice;
}