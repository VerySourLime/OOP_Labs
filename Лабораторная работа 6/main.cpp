#include <iostream>
#include <vector>
#include <ctime> // Для srand и time

#include "List.h"
#include "Iterator.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел
    List list;

    // Добавление случайных значений в список
    for (int i = 0; i < 5; ++i)
        list.push_back(rand() % 100);

    list.print();

    // Проверка доступа к элементу
    cout << "Element at index 2: " << list[2] << endl;

    // Изменение размера списка
    list(10);

    // Увеличение каждого элемента на 10
    list += 10;

    list.print();

    return 0; // Явное возвращение 0
}
